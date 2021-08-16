#include "common/logger.h"

namespace biscuit::common {

LoggerConfig::LoggerConfig() {
#ifndef NDEBUG
  spdlog::set_level(spdlog::level::debug);
#endif
  spdlog::flush_every(std::chrono::seconds(ASYNC_FLUSH_TIME));
}

const std::shared_ptr<spdlog::logger> Logger::LOG = spdlog::basic_logger_mt("default_logger", LOG_FILE);
const LoggerConfig Logger::CONFIG = LoggerConfig();

void Logger::Debug(const std::string &message) { Logger::LOG->debug(message); }

void Logger::Info(const std::string &message) { Logger::LOG->info(message); }

void Logger::Warn(const std::string &message) { Logger::LOG->warn(message); }

void Logger::Error(const std::string &message) { Logger::LOG->error(message); }

}  // namespace biscuit::common
