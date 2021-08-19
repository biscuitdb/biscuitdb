#include "common/dbconfig.h"

#include <fstream>
#include <iostream>

namespace biscuit::common {

json DBConfig::ReadConfig(const char *path) {
  std::ifstream fin = std::ifstream(path);

  if (fin.is_open()) {
    json j;
    fin >> j;
    fin.close();
    return j;
  }
  /* Throw exceptions for io error. */
  throw std::ifstream::failure("invalid path for config file: " + std::string(path));
}

json DBConfig::config = nullptr;
bool DBConfig::cached = false;

const json &DBConfig::GetConfig() {
  if (!cached) {
    config = ReadConfig(CONFIG_PATH);
    cached = true;
  }
  return config;
}

bool DBConfig::IsCached() { return cached; }

}  // namespace biscuit::common
