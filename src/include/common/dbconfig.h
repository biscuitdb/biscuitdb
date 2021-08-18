#ifndef BISCUIT_COMMON_DBCONFIG_H
#define BISCUIT_COMMON_DBCONFIG_H

/**
 * This stuff doesn't work.
 */

#include <string>

#include "yaml-cpp/yaml.h"

namespace biscuit::common {

const char CONFIG_PATH[] = "config.yml";

class DBConfig {
  static bool cached;
  static YAML::Node CONFIG;

  static void InitCache();

 public:
  static const std::string GetKey(const std::string &key);
  static const int GetKeyAsInt(const std::string &key);
};

}  // namespace biscuit::common

#endif
