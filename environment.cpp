#include <iostream>
#include <map>
#include <memory>

#include "environment.hpp"
#include "folder.hpp"
#include "file_system_entity.hpp"

std::map<std::string, std::shared_ptr<FileSystemEntity>> Environment::paths = { {"/", std::make_shared<Folder>("/")}};
std::string Environment::current_path = "/";
Folder* Environment::p_current_folder = dynamic_cast<Folder*>(/*&*/Environment::paths.at("/").get());

std::string Environment::active_path = "/";
Folder* Environment::p_active_folder = dynamic_cast<Folder*>(/*&*/Environment::paths.at("/").get());


void Environment::resetActiveFolder(){
  Environment::p_active_folder = Environment::p_current_folder; 
}

void Environment::changeDirectory(){
  Environment::p_current_folder = Environment::p_active_folder; 
}
