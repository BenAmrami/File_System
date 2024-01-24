#include <iostream>
#include <vector>

//input: text & delimiter to split with
//output: vector containing the split string by sequence
std::vector<std::string> split(const std::string &txt, const std::string delimeter)
{
  
  std::vector<std::string> vec;
  size_t start_pos = 0;
  size_t del_pos = txt.find(delimeter);

  while(del_pos!= std::string::npos){
    vec.push_back(txt.substr(start_pos, del_pos - start_pos));
    start_pos = del_pos + 1;
    del_pos = txt.find(delimeter, start_pos);
  }

  vec.push_back(txt.substr(start_pos, txt.length() - start_pos));
  
  return vec;
}