#pragma once

#include <vector>
#include <map>
#include <memory>

#include "file.hpp"
#include "file_system_entity.hpp"
#include "commands.hpp"

class Folder : public FileSystemEntity {
  private:
  std::string name;
  std::map<std::string, std::shared_ptr<FileSystemEntity>> files;
  
  
  public:

    Folder(std::string name);

    std::shared_ptr<FileSystemEntity> SearchEntity(std::string entity_name);
    bool addFile(std::shared_ptr<FileSystemEntity> entity);
    bool removeFile(std::shared_ptr<FileSystemEntity> entity);
    // std::vector<std::string> displayFiles();
    
    friend class commands;
    friend std::string ls(std::vector<std::string> params, std::vector<std::string> input);
};