#include <iostream>

#include "text_file.hpp"



  TextFile::TextFile(std::string name, std::string contents)
  : File(name, ".txt"), contents(contents) {}

  inline std::string TextFile::readContents(){
    return this->contents;
  }

  inline void TextFile::replaceContents(std::string &new_contents){
    this->contents = new_contents;
  }
