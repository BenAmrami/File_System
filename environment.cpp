#include <iostream>
#include <map>

#include "environment.hpp"
#include "folder.hpp"
#include "file_system_entity.hpp"

  std::map<std::string, FileSystemEntity> Environment::paths = { {"/", Folder("/")} };

  std::string Environment::current_path = "/";
  Folder* Environment::p_current_folder = dynamic_cast<Folder*>(&Environment::paths.at("/"));

  std::string Environment::active_path = "/";
  Folder* Environment::p_active_folder = dynamic_cast<Folder*>(&Environment::paths.at("/"));

  bool Environment::change_directory = 0;