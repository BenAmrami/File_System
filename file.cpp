#include <iostream>

#include "file.hpp"


  File::File(std::string name, std::string extension)
  : FileSystemEntity(name), extension(extension) {}

  std::string File::getName(){
    return this->name;
  }

  void File::rename (std::string file_name){
    this->name = file_name;
  }
