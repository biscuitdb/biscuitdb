#include "common/dbconfig.h"

#include "gtest/gtest.h"

using biscuit::common::DBConfig;

TEST(dbconfig, DBConfigShouldReadTestKeyValue) {
  std::string value = DBConfig::GetConfig()["test"]["key"];
  ASSERT_EQ("value", value);
  ASSERT_TRUE(DBConfig::IsCached());
}
