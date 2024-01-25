#include <iostream>

#include "folder.hpp"
#include "file.hpp"
#include "text_file.hpp"
#include "helper.hpp"
#include "commands.hpp"

int main(){
  
  std::cout << "\033[1;31m" << "wassap" << "\033[0m" << std::endl;
  Folder Ben = Folder("Ben");
  Ben.addFile(TextFile("hello_world!"));
  std::string test = "this is a test string! :D";

  std::vector<std::string> vec = split(test, "s");
  for (size_t i=0; i<vec.size(); i++){
    std::cout << vec[i] << std::endl;
  }
  mkdir(vec, {"Benchuk!", "Benchuk!/cool"});
  cd(vec, "Benchuk!");
  

  
  std::cout << test << std::endl;

  return 0;

}