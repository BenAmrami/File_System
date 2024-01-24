#pragma once

#include <iostream>
#include <vector>
#include <map>

#include "folder.hpp"
#include "file_system_entity.hpp"

class Environment{
  public:
    static std::map<std::string, FileSystemEntity> paths;
    static std::string current_path;
    static Folder* p_current_folder;
    static std::string active_path;
    static Folder* p_active_folder;
    static bool change_directory;
};