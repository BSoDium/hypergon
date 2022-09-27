#include "logger.hpp"

LogMessage::LogMessage(const std::string origin, const std::string message, const LogLevel level)
{
  this->content = message;
  this->level = level;
  this->origin = origin;
}

void Logger::setLevel(LogLevel level)
{
  Logger::level = level;
}

void Logger::log(LogMessage message)
{
  std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

  if (message.level >= Logger::level)
  {
    char buffer[80];
    std::strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", std::localtime(&now));
    std::string origin = message.origin == "" ? "Hypergon" : message.origin;
    std::cout << "[" << buffer << "] " << origin << ": " << message.content << std::endl;
  }

  if (Logger::history.entries.size() > MAX_LOG_HISTORY)
  {
    Logger::history.entries.erase(Logger::history.entries.begin());
  }

  Logger::history.entries.push_back(LogEntry(message, now));
}

void Logger::debug(std::string message, std::string origin)
{
  Logger::log(LogMessage(origin, message, LogLevel::DEBUG));
}

void Logger::info(std::string message, std::string origin)
{
  Logger::log(LogMessage(origin, message, LogLevel::INFO));
}

void Logger::warn(std::string message, std::string origin)
{
  Logger::log(LogMessage(origin, message, LogLevel::WARN));
}

void Logger::error(std::string message, std::string origin)
{
  Logger::log(LogMessage(origin, message, LogLevel::ERROR));
}

void Logger::fatal(std::string message, std::string origin)
{
  Logger::log(LogMessage(origin, message, LogLevel::FATAL));
}

void LogEmitter::debug(std::string message)
{
  Logger::debug(message, this->origin);
}

void LogEmitter::info(std::string message)
{
  Logger::info(message, this->origin);
}

void LogEmitter::warn(std::string message)
{
  Logger::warn(message, this->origin);
}

void LogEmitter::error(std::string message)
{
  Logger::error(message, this->origin);
}

void LogEmitter::fatal(std::string message)
{
  Logger::fatal(message, this->origin);
}