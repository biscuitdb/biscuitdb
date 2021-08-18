#include "common/logger.h"

#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"

namespace biscuit::common {

const char LoggerConfig::DEFAULT[] = "default";
const char LoggerConfig::DAILY_ROTATE[] = "daily-rotate";
const char LoggerConfig::ROTATE[] = "rotate";

LoggerConfig::LoggerConfig() {
#ifndef NDEBUG
  spdlog::set_level(spdlog::level::debug);
#endif
  spdlog::flush_every(std::chrono::seconds(ASYNC_FLUSH_TIME));
}

/**
 * Creates new logger object from LOGGER_TYPE.
 * If only C++ could switch on strings :(.
 */
std::shared_ptr<spdlog::logger> LoggerConfig::GetNewLogger() const {
  if (LOGGER_TYPE == std::string(DAILY_ROTATE)) {
    return spdlog::daily_logger_mt(LOGGER_NAME, LOG_PATH);
    // NOLINTNEXTLINE --no-else-after-return
  } else if (LOGGER_TYPE == std::string(ROTATE)) {
    return spdlog::rotating_logger_mt(LOGGER_NAME, LOG_PATH, ROTATING_LOG_MAX_SIZE, ROTATING_LOG_COUNT);
  } else {
    return spdlog::basic_logger_mt(LOGGER_NAME, LOG_PATH);
  }
}

const LoggerConfig Logger::CONFIG = LoggerConfig();
const std::shared_ptr<spdlog::logger> Logger::LOG = Logger::CONFIG.GetNewLogger();

void Logger::Debug(const std::string &message) { Logger::LOG->debug(message); }

void Logger::Info(const std::string &message) { Logger::LOG->info(message); }

void Logger::Warn(const std::string &message) { Logger::LOG->warn(message); }

void Logger::Error(const std::string &message) { Logger::LOG->error(message); }

}  // namespace biscuit::common
