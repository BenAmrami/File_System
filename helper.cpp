#include <iostream>
#include <vector>

//input: text & delimiter to split with
//output: vector containing the split string by sequence
//description: splits the text by the delimeter given and returns a vector of the split parts
std::vector<std::string> split(const std::string &txt, const std::string delimeter)
{
  
  std::vector<std::string> vec;
  size_t start_pos = 0; // start position
  size_t del_pos = txt.find(delimeter); //delimeter position

  //if found delimeter
  while(del_pos!= std::string::npos){

    //preventing null entries to vec
    if (start_pos != del_pos){
      //insert sub string between delimeters
      vec.push_back(txt.substr(start_pos, del_pos - start_pos));
    }
    //new starting position after delimeter position
    start_pos = del_pos + 1;
    //next delimeter position
    del_pos = txt.find(delimeter, start_pos);
  }

  //preventing null entries to vec
  if (start_pos != txt.size()){
    vec.push_back(txt.substr(start_pos, txt.length() - start_pos));
  }
  
  return vec;
}