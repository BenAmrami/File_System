#pragma once

#include <iostream>

#include "file_system_entity.hpp"

class File : public FileSystemEntity {
  protected:
    std::string name;
    std::string extension;
    std::string path;
    
  public:

    File(std::string name, std::string extention = "");


    friend class Commands;

    
};