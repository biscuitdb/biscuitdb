#ifndef BISCUIT_COMMON_DBCONFIG_H
#define BISCUIT_COMMON_DBCONFIG_H

#include <string>

#include "nlohmann/json.hpp"
using json = nlohmann::json;

namespace biscuit::common {

/**
 * Path for config file.
 */ 
const char CONFIG_PATH[] = "config.json";

/**
 * Global config reader. Initialized at bootstrap.
 */
class DBConfig {
  static json config;
  static bool cached;
  /**
   * Reads json files and returns parsed json object or nullptr in case bad path.
   */
  static json ReadConfig(const char *path);

 public:
  /**
   * Get reference to config json.
   * Usage: DBConfig::GetConfig()["key"] ...
   */
  static const json &GetConfig();
};

}  // namespace biscuit::common

#endif
