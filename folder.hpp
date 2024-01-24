#pragma once

#include <vector>
#include <map>

#include "file.hpp"
#include "file_system_entity.hpp"
#include "commands.hpp"

class Folder : public FileSystemEntity {
  private:
  std::string name;
  std::map<std::string, FileSystemEntity> files;
  
  
  public:

    Folder(std::string name);

    FileSystemEntity& SearchEntity(std::string entity_name);
    bool addFile(File file);
    bool removeFile(File &file);

    friend class Commands;
};