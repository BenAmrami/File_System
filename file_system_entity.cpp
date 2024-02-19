#include <iostream>

#include "file_system_entity.hpp"

FileSystemEntity::FileSystemEntity(std::string name)
  : name(name) {}

//returns entity name
std::string FileSystemEntity::getName(){
  return this->name;
}
// rename this entity's name
void FileSystemEntity::rename (std::string file_name){
  this->name = file_name;
}