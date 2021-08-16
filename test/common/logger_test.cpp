#include "common/logger.h"

#include "gtest/gtest.h"

/**
 * NOTE: Logging is configured asynchronously.
 * Module tested manually.
 */

TEST(logger, LoggerShouldLogDebugMessage) { LOG_DEBUG("debug: test message"); }

TEST(logger, LoggerShouldLogInfoMessage) { LOG_INFO("info: test message"); }

TEST(logger, LoggerShouldLogWarningMessage) { LOG_WARN("warn: test message"); }

TEST(logger, LoggerShouldLogErrorMessage) { LOG_ERROR("error: test message"); }
