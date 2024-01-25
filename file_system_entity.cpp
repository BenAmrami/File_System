#include <iostream>

#include "file_system_entity.hpp"

FileSystemEntity::FileSystemEntity(std::string name)
  : name(name) {}

std::string FileSystemEntity::getName(){
  return this->name;
}

void FileSystemEntity::rename (std::string file_name){
  this->name = file_name;
}