#include "common/logger.h"

#include "gtest/gtest.h"

/**
 * NOTE: Logging is configured asynchronously.
 * Module tested manually.
 */

TEST(logger, LoggerShouldLogDebugMessage) { LOG_DEBUG("test debug message"); }

TEST(logger, LoggerShouldLogInfoMessage) { LOG_INFO("test info message"); }

TEST(logger, LoggerShouldLogWarningMessage) { LOG_WARN("test warn message"); }

TEST(logger, LoggerShouldLogErrorMessage) { LOG_ERROR("test error message"); }
