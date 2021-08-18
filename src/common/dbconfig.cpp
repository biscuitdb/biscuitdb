#include "common/dbconfig.h"

#include <iostream>

namespace biscuit::common {

bool DBConfig::cached = false;
YAML::Node DBConfig::CONFIG = YAML::Node();

void DBConfig::InitCache() {
  if (!cached) {
    CONFIG = YAML::LoadFile(CONFIG_PATH);
    cached = true;
  }
}

const std::string DBConfig::GetKey(const std::string &key) {
  InitCache();
  if (CONFIG[key]) {
    return CONFIG[key].as<std::string>();
  }
  return nullptr;
}

const int DBConfig::GetKeyAsInt(const std::string &key) {
  InitCache();
  if (CONFIG[key]) {
    return CONFIG[key].as<int>();
  }
  return 0;
}

}  // namespace biscuit::common
