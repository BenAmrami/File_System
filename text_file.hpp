#pragma once

#include <iostream>

#include "file.hpp"
#include "commands.hpp"
class TextFile : public File {
  private:
    std::string contents;

  public:

    TextFile(std::string name, std::string contents = "");

    inline std::string readContents();
    inline void replaceContents(std::string &new_contents);
};