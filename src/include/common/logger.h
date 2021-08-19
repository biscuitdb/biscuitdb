#ifndef BISCUIT_COMMON_LOGGER_H
#define BISCUIT_COMMON_LOGGER_H

#include <memory>
#include <string>

#include "common/dbconfig.h"
#include "spdlog/spdlog.h"

namespace biscuit::common {

/**
 * LoggerConfig initializes spdlog to print debug messages and async logging.
 */
class LoggerConfig {
  /* Log file path */
  const std::string LOG_PATH = DBConfig::GetConfig()["logger"]["log_path"];
  /* Logger name */
  const std::string LOGGER_NAME = DBConfig::GetConfig()["logger"]["logger_name"];
  /* Type of logger */
  const std::string LOGGER_TYPE = DBConfig::GetConfig()["logger"]["logger_type"];
  /* Max file size for rotating log */
  const int ROTATING_LOG_MAX_SIZE = DBConfig::GetConfig()["logger"]["rotating_log_max_size"];
  /* File count for rotating log */
  const int ROTATING_LOG_COUNT = DBConfig::GetConfig()["logger"]["rotating_log_count"];
  /* Flush to disk every n seconds */
  const int ASYNC_FLUSH_TIME = DBConfig::GetConfig()["logger"]["async_flush_time"];

  /* Valid Logger Types */
  static const char DAILY_ROTATE[];
  static const char ROTATE[];

 public:
  LoggerConfig();

  /**
   * Creates and returns new logger with set congig.
   */
  std::shared_ptr<spdlog::logger> GetNewLogger() const;
};

/**
 * Logger class for debuging.
 * Note:
 * This will not log debug messages when build type is Release.
 * Other log messages are printed regardless.
 * Use debug() where applicable for optimal performance in production.
 */
class Logger {
  static const LoggerConfig CONFIG;
  static const std::shared_ptr<spdlog::logger> LOG;

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
