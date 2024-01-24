#pragma once

#include <iostream>

#include <vector>

struct CommandParameters{
  std::string command;
  std::vector<std::string> params;
  std::vector<std::string> input;
} ;

CommandParameters parse(const std::string &user_input);