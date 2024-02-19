#include <iostream>
#include <map>
#include <memory>

#include "environment.hpp"
#include "folder.hpp"
#include "file_system_entity.hpp"

std::map<std::string, std::shared_ptr<FileSystemEntity>> Environment::paths = { {"/", std::make_shared<Folder>("/")}};

//current path the command line is standing on
std::string Environment::current_path = "/";
std::shared_ptr<Folder> Environment::p_current_folder = std::static_pointer_cast<Folder>(Environment::paths.at("/"));

//active path that the command is using
std::string Environment::active_path = "/";
std::shared_ptr<Folder> Environment::p_active_folder = std::static_pointer_cast<Folder>(Environment::paths.at("/"));

//reset active path to stand on the current path
void Environment::resetActiveFolder(){
  Environment::p_active_folder = Environment::p_current_folder; 
}

//change the current path to active path (cd command)
void Environment::changeDirectory(){
  Environment::p_current_folder = Environment::p_active_folder; 
}
