#include <iostream>

#include "folder.hpp"
#include "file.hpp"
#include "text_file.hpp"
#include "helper.hpp"
#include "commands.hpp"

int main(){
  
  
  
  std::vector<std::string> vec;

  mkdir(vec, {"Benchuk!", "Benchuk!/cool"});
  cd(vec, "Benchuk!");
  



  return 0;

}