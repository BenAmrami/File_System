#include <iostream>
#include <vector>
#include <algorithm>

#include "folder.hpp"
#include "file.hpp"


Folder::Folder(std::string name)
: FileSystemEntity(name)/*, files({{".."},{NEED TO COMPLETE THIS}}) */ {}


FileSystemEntity& Folder::SearchEntity(std::string name){
  return (files.find(name) != files.end()) ? files.at(name) : *this ;
}

bool Folder::addFile(File file){
  //if file doesn't exist
  if (this->files.find(file.getName()) == this->files.end()){

    this->files.insert({file.getName(),file});
    return 1;
  }

  std::cout << "ERROR: File name already exists" << std::endl;
  return 0;
}

bool Folder::removeFile(File &file){
  //if file doesn't exist
  if (this->files.find(file.getName()) != this->files.end()){

    this->files.erase(file.getName());
    return 1;
  }

  std::cout << "ERROR: File does not exist" << std::endl;
  return 0;
}
