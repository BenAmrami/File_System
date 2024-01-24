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
  std::vector<std::string> div_path = split(path, "/");


  if (path.at(0) == '/') {
    div_path.insert(div_path.begin(), "/");
  }
  if (Environment::paths.find(div_path.front()) == Environment::paths.end()){
    Environment::p_active_folder = static_cast<Folder*>(&Environment::paths.find(div_path.front())->second);

  }



  for (size_t i = 0; i<div_path.size(); i++){
      
    FileSystemEntity &temp = Environment::p_active_folder->SearchEntity(*div_path.begin());
    //if the folder exists
    if (typeid(temp) != typeid(Folder)){
      std::cout << path << ": Not a directory";
      break; //?
    }
    if ( (*div_path.begin() != "." && &temp != Environment::p_active_folder)) {

      Environment::p_active_folder = static_cast<Folder*>(&temp);

    } else {
      std::cout << path << ": No such file or directory";
      break;
    }

  }

  if (Environment::change_directory){
    Environment::p_current_folder = Environment::p_active_folder;
  }
  //---lambda---
  // std::function<Folder&()> navigate;
  // navigate = [&div_path, path, navigate]() {
  //   
  //   //if the path has ended
  //   if (div_path.empty()){
  //     return Environment::p_active_folder;
  //   }
  //   
  //   FileSystemEnity temp = Environment::p_active_folder->searchFile(*div_path.begin());
  //   //if the folder exists
  //   if (typeid(temp) != typeid(Folder)){
  //     std::cout << path << ": No such file or directory";
  //     return Environment::p_current_folder;
  //   }
  //
  //   if ( (*div_path.begin() != "." && &temp != Environment::p_active_folder)) {
  //
  //     Environment::p_active_folder = dynamic_cast<Folder*>(&temp);
  //     div_path.erase(div_path.begin());
  //     return &navigate();
  //
  //   } else {
  //     std::cout << path << ": No such file or directory";
  //     return Environment::p_current_folder;
  //   }
  //
  // 
  // }
  //---end lambda ---
  return "";
}



std::string mkdir(std::vector<std::string> params, std::vector<std::string> input){
  std::vector<std::vector<std::string>> input_vec;
  
  for (size_t i =0; i<input.size(); i++) {
    input_vec.push_back(split(input.at(i)));
  }
  
  for (size_t i =0; i<input_vec.size(); i++){
    // go to location and create the folder there. need to play with the p_active_folder
  }

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


};