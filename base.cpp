#include <iostream>

#include "folder.hpp"
#include "file.hpp"
#include "text_file.hpp"
#include "helper.hpp"
#include "commands.hpp"

int main(){
  
  std::string input;
  do {
    std::cout << ">>";
    //user input
    std::getline(std::cin, input);

    parse(input);

  } while (input != "exit");

  return 0;

}