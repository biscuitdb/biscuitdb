#ifndef BISCUIT_COMMON_LOGGER_H
#define BISCUIT_COMMON_LOGGER_H

#include <memory>
#include <string>

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

namespace biscuit::common {

/**
 * log file path.
 */
const char LOG_FILE[] = "logs/biscuitdb.log";

/**
 * LoggerConfig initializes spdlog to print debug messages and async logging.
 */
class LoggerConfig {
  /* Flush to disk every 3 seconds */
  const int ASYNC_FLUSH_TIME = 3;

 public:
  LoggerConfig();
};

/**
 * Logger class for debuging.
 * Note:
 * This will not log debug messages when build type is Release.
 * Other log messages are printed regardless.
 * Use debug() where applicable for optimal performance in production.
 */
class Logger {
  static const std::shared_ptr<spdlog::logger> LOG;
  static const LoggerConfig CONFIG;

 public:
  /**
   * Logs debug message.
   */
  static void Debug(const std::string &message);
  /**
   * Logs debug message.
   */
  static void Info(const std::string &message);
  /**
   * Logs debug message.
   */
  static void Warn(const std::string &message);
  /**
   * Logs debug message.
   */
  static void Error(const std::string &message);
};

#define LOG_DEBUG(s) biscuit::common::Logger::Debug(s)
#define LOG_INFO(s) biscuit::common::Logger::Info(s)
#define LOG_WARN(s) biscuit::common::Logger::Warn(s)
#define LOG_ERROR(s) biscuit::common::Logger::Error(s)

}  // namespace biscuit::common

#endif
