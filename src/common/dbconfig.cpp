#include "common/dbconfig.h"

#include <fstream>
#include <iostream>

namespace biscuit::common {

json DBConfig::ReadConfig(const char *path) {
  std::ifstream fin = std::ifstream(path);
  if (fin.good()) {
    json j;
    fin >> j;
    return j;
  }
  return nullptr;
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

}  // namespace biscuit::common
