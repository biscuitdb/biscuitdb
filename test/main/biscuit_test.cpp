#include "main/biscuit.h"

#include "gtest/gtest.h"

TEST(biscuit, dummy) { ASSERT_TRUE(true); }

TEST(biscuit, Radd) { ASSERT_EQ(100, biscuit::Radd(0, 100)); }
