#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <typeinfo>

#include "environment.hpp"
#include "commands.hpp"
#include "helper.hpp"



CommandParameters parse(const std::string &user_input){
  std::vector<std::string> vec = split(user_input, " ");
  struct CommandParameters cmd;
  std::vector<CommandParameters> commands;

  for (size_t i = 0; i<vec.size(); i++){}
  return cmd;
}

std::string cd(std::vector<std::string> params, std::string path){

  std::vector<std::string> div_path = splitPath(path);
  //    reason of error, type of error
  std::pair<std::string, std::string> feedback_pair = navigate(div_path);
  //if there is an error
  if (!(feedback_pair.first == "" && feedback_pair.second == "")){
    //print error
    std::cout << path << ": " << feedback_pair.second;
    return "false";
  }


  Environment::changeDirectory();
  return "true";
}



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
      std::cout << input.at(i) << ": " << feedback_pair.second;
      return "false";
    }
    //adding new Folder in its requested location
    Environment::p_active_folder->addFile(std::make_shared<Folder>(folder_name));
    // go to location and create the folder there. need to play with the p_active_folder
  }
  Environment::resetActiveFolder();
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

std::vector<std::string> splitPath(std::string path){
  std::vector<std::string> div_path = split(path, "/");

  if (path.at(0) == '/') {
    div_path.insert(div_path.begin(), "/");
  }
  else if (Environment::paths.find(div_path.front()) != Environment::paths.end()){
    Environment::p_active_folder = std::static_pointer_cast<Folder>(Environment::paths.find(div_path.front())->second);

  }
  return div_path;
}

//input: divided path to navigate into
//output: pair of strings
std::pair<std::string, std::string> navigate(std::vector<std::string> div_path){
  for (size_t i = 0; i<div_path.size(); i++){
      
    std::shared_ptr<FileSystemEntity> temp = Environment::p_active_folder->SearchEntity(div_path.at(i));
    //if the folder exists
    if (typeid(*temp) != typeid(Folder)){ //check if works DOES NOT WORK
      Environment::resetActiveFolder();
      return {div_path.at(i), "Not a directory"};
    }
    // if its both (default and specified current folder ["."]) 
    if ( (div_path.at(i) == "." && temp == Environment::p_active_folder)) {
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