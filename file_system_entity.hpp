#pragma once

#include <iostream>

class FileSystemEntity {
  protected:
    std::string name;

  public:
    FileSystemEntity(std::string name/*" = ERROR"*/ );
    virtual ~FileSystemEntity() = default;

    std::string getName();
    void rename(std::string file_name);
};