#pragma once

#include <iostream>

#include <vector>

struct CommandParameters{
  std::string command;
  std::vector<std::string> params;
  std::vector<std::string> input;
} ;

CommandParameters parse(const std::string &user_input);

std::string cd(std::vector<std::string> params, std::string path);
std::string mkdir(std::vector<std::string> params, std::vector<std::string> input);
std::string ls(std::vector<std::string> params, std::vector<std::string> input);
std::string cat(std::vector<std::string> params, std::vector<std::string> input);

std::vector<std::string> splitPath(std::string path);
std::pair<std::string, std::string> navigate(std::vector<std::string> div_path);