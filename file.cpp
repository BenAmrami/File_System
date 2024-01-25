#include <iostream>

#include "file.hpp"


  File::File(std::string name, std::string extension)
  : FileSystemEntity(name), extension(extension) {}


