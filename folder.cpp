#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "folder.hpp"
#include "file.hpp"


Folder::Folder(std::string name)
: FileSystemEntity(name)/*, files({{".."},{NEED TO COMPLETE THIS}}) */ {}


FileSystemEntity& Folder::SearchEntity(std::string name){
  return (files.find(name) != files.end()) ? files.at(name) : *this ;
}

bool Folder::addFile(FileSystemEntity entity){
  //if entity doesn't exist
  if (this->files.find(entity.getName()) == this->files.end()){

    this->files.insert({entity.getName(),entity});
    return 1;
  }

  std::cout << "ERROR: File name already exists" << std::endl;
  return 0;
}

bool Folder::removeFile(FileSystemEntity &entity){
  //if entity doesn't exist
  if (this->files.find(entity.getName()) != this->files.end()){

    this->files.erase(entity.getName());
    return 1;
  }

  std::cout << "ERROR: File does not exist" << std::endl;
  return 0;
}
