#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

#include "folder.hpp"
#include "file.hpp"
#include "file_system_entity.hpp"
#include "environment.hpp"


Folder::Folder(std::string name)
: FileSystemEntity(name) {
  files.insert({{"."}, {std::shared_ptr<Folder>(this)}}); // this folder
  files.insert({{".."}, {Environment::p_active_folder}}); // previous folder

}

//returns entity if exists, else returns itself
std::shared_ptr<FileSystemEntity> Folder::SearchEntity(std::string name){
  return (files.find(name) != files.end()) ? files.at(name) : files.at(".") ;
} 

bool Folder::addFile(std::shared_ptr<FileSystemEntity> entity){
  //if entity doesn't exist
  if (this->files.find(entity->getName()) == this->files.end()){

    this->files.insert({entity->getName(),entity});
    return true;
  }

  std::cout << "ERROR: File name already exists" << std::endl;
  return false;
}

bool Folder::removeFile(std::shared_ptr<FileSystemEntity> entity){
  //if entity doesn't exist
  if (this->files.find(entity->getName()) != this->files.end()){

    this->files.erase(entity->getName());
    return true;
  }

  std::cout << "ERROR: File does not exist" << std::endl;
  return false;
}


