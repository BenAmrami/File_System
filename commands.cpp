#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <typeinfo>

#include "environment.hpp"
#include "commands.hpp"
#include "helper.hpp"


//input: command string to parse from user
//output: command parameters (none for now)
//description: parses user command and interprets it
CommandParameters parse(const std::string &user_input){
  //split commands
  std::vector<std::string> cmd_vec = split(user_input, "|");

  std::vector<CommandParameters> commands;
  struct CommandParameters temp;
  
  //loop each command
  for (const auto& cmd_str : cmd_vec) {
      //split command input
      std::vector<std::string> vec = split(cmd_str, " ");
      CommandParameters cmd;

      
      if (!vec.empty()) {
          //command name
          cmd.command = vec.front();
          //parameters and input
          for (size_t j = 1; j < vec.size(); ++j) {
              //if its a parameter
              if (vec[j].at(0) == '-') {
                  cmd.params.push_back(vec[j]);
              //command's input
              } else {
                  cmd.input.push_back(vec[j]);
              }
          }
          commands.push_back(std::move(cmd)); //transfer ownership and store in commands
      }
  }

  //match corresponding command with actions
  for (const auto& cmd : commands){
    if (cmd.command == "mkdir"){
      mkdir(cmd.params, cmd.input);
    } else if (cmd.command == "cd"){
      cd(cmd.params, cmd.input.at(0));
    } else if (cmd.command == "ls"){
      ls(cmd.params, cmd.input);
    } else {
      std::cout << cmd.command << ": Unknown command" << std::endl;
    }
    // Environment::resetActiveFolder();
  }
  //change active folder back to current folder
  Environment::resetActiveFolder();
  return temp;
}

//input: command parameters (currently none) and path
//output: error string (currently unused)
//description: changes directory to the desired folder
std::string cd(std::vector<std::string> params, std::string path){

  std::vector<std::string> div_path = splitPath(path);
  //    reason of error, type of error
  std::pair<std::string, std::string> feedback_pair = navigate(div_path);
  
  //if there is an error
  if (!(feedback_pair.first == "" && feedback_pair.second == "")){
    //print error
    std::cout << path << ": " << feedback_pair.second << std::endl;
    return "false";
  }

  //change directory;
  Environment::changeDirectory();
  return "true";
}


//input: command parameters (currently none) and input
//output: error string (currently unused)
//description: create a new directory in specified location
std::string mkdir(std::vector<std::string> params, std::vector<std::string> input){
  
  std::vector<std::string> div_path;
  for (size_t i =0; i<input.size(); i++){
    div_path = splitPath(input.at(i));
    
    //removing last element (the name)
    std::string folder_name = div_path.back();
    div_path.pop_back();
    
    //    reason of error, type of error
    std::pair<std::string, std::string> feedback_pair = navigate(div_path);
  
    //if there is an error
    if (!(feedback_pair.first == "" && feedback_pair.second == "")){
      //print error
      std::cout << input.at(i) << ": " << feedback_pair.second << std::endl;
      return "false";
    }
    
    //if directory already exists
    if (Environment::p_active_folder->SearchEntity(folder_name) != Environment::p_active_folder){
      std::cout << "Directory already exists" << std::endl;
      return "false";
    }

    //adding new Folder in its requested location
    Environment::p_active_folder->addFile(std::make_shared<Folder>(folder_name));
    Environment::resetActiveFolder();
  }
  //reset the active folder pointer
  Environment::resetActiveFolder();
  return "true";
}


//input: command parameters (currently none) and input
//output: error string (currently unused)
//description: present current directory's content files
std::string ls(std::vector<std::string> params, std::vector<std::string> input){

  //    reason of error, type of error
  std::pair<std::string, std::string> feedback_pair = navigate(input);

  //if there is an error
  if (!(feedback_pair.first == "" && feedback_pair.second == "")){
    //print error
    std::cout << ": " << feedback_pair.second << std::endl;
    return "false";
  }
  
  auto fold = Environment::p_active_folder;
  int row_count = 0;

  //looping folder content
  for (const auto& file: fold->files){
    std::cout << file.first; //file name
    row_count++;
    //checks if it should print in a new row
    if (row_count == 5){
      std::cout << std::endl;
      row_count = 0;
    } else{
      std::cout << "\t";
    }
  }
  std::cout << std::endl;

  return "test";
}

std::string cat(std::vector<std::string> params, std::vector<std::string> input){

  return "test";
}

using std::string;
using std::vector;

// std::map<string, std::function<string(vector<string>, vector<string>)>> function_map =
std::map<string, std::function<void()>> function_map =
{ 
  // {"cd", cd},
  // {"mkdir", mkdir}
};


//input: a (supposedly) path to split
//output: a vector containing the split path
//description: a helper function to split a given path
std::vector<std::string> splitPath(std::string path){
  //split by "/"
  std::vector<std::string> div_path = split(path, "/");

  //'extreme case' of the root folder
  if (path.at(0) == '/') {
    div_path.insert(div_path.begin(), "/");
  }
  //if found a path variable (does not contain any atm)
  else if (Environment::paths.find(div_path.front()) != Environment::paths.end()){
    //change active folder to it (maybe should add the string instead, more work though)
    Environment::p_active_folder = std::static_pointer_cast<Folder>(Environment::paths.find(div_path.front())->second);

  }
  //the divided path
  return div_path;
}

//input: divided path to navigate into
//output: pair of strings (feedback pair)
//description: navigates the directories by the path given
std::pair<std::string, std::string> navigate(std::vector<std::string> div_path){
  // for each entity in the path (maybe use iterative for?)
  for (size_t i = 0; i<div_path.size(); i++){
    
    //entity holder
    std::shared_ptr<FileSystemEntity> temp = Environment::p_active_folder->SearchEntity(div_path.at(i));

    //if the folder does not exist
    if (typeid(*temp) != typeid(Folder)){
      Environment::resetActiveFolder();
      return {div_path.at(i), "Not a directory"};
    }

    //if the entity does not exist
    if ( (div_path.at(i) != "." &&  temp == Environment::p_active_folder)) {
      Environment::resetActiveFolder();
      //did not find entity
      return {div_path.at(i), "No such file or directory"};

    } else {  
      //changing active folder to the next folder
      Environment::p_active_folder = std::static_pointer_cast<Folder>(temp);
    }
  }
  //default, no errors
  return {"",""};

}