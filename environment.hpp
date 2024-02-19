#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <memory>

#include "folder.hpp"
#include "file_system_entity.hpp"

class Environment{
  public:
    // static std::map<std::string, FileSystemEntity> paths;
    static std::map<std::string, std::shared_ptr<FileSystemEntity>> paths;
    static std::string current_path;
    // static Folder* p_current_folder;
    static std::shared_ptr<Folder> p_current_folder;
    static std::string active_path;
    // static Folder* p_active_folder;
    static std::shared_ptr<Folder> p_active_folder;

    
    static void resetActiveFolder();
    static void changeDirectory();
};