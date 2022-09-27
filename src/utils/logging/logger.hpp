#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <any>
#include <source_location>
#include <string.h>

#define MAX_LOG_HISTORY 500
#define EMPTY_ORIGIN ""

enum class LogLevel
{
  DEBUG,
  INFO,
  WARN,
  ERROR,
  FATAL
};

/**
 * @brief Log message content.
 */
struct LogMessage
{
  /** Log level. */
  LogLevel level;
  /** Origin of the message (e.g. "loader", "engine", etc.). */
  std::string origin;
  /** Message to log. */
  std::string content;
  LogMessage(const std::string origin, const std::string message, const LogLevel level = LogLevel::INFO);
  LogMessage(const std::string message, const LogLevel level = LogLevel::INFO) : LogMessage(EMPTY_ORIGIN, message, level) {}
};

struct LogEntry : public LogMessage
{
  /** Time of the log. */
  std::time_t time;
  LogEntry(LogMessage message, std::time_t time) : LogMessage(message)
  {
    this->time = time;
  }
};

/**
 * @brief Log message history.
 */
struct LogHistory
{
  /** Vector of entries. */
  std::vector<LogEntry> entries;
  LogHistory()
  {
    this->entries = std::vector<LogEntry>();
  }
};

/**
 * @brief Logger static class.
 */
class Logger
{
private:
  inline static LogLevel level = LogLevel::INFO;
  inline static LogHistory history = LogHistory();

public:
  /**
   * Set the log level.
   */
  static void setLevel(LogLevel level);

  /**
   * Log a message.
   */
  static void log(LogMessage message);

  /**
   * Log an app-wide debug message.
   *
   * @param message Message to log.
   * @param origin Origin of the message.
   */
  static void debug(std::string message, std::string origin = EMPTY_ORIGIN);

  /**
   * Log an app-wide info message.
   *
   * @param message Message to log.
   * @param origin Origin of the message.
   */
  static void info(std::string message, std::string origin = EMPTY_ORIGIN);

  /**
   * Log an app-wide warning message.
   *
   * @param message Message to log.
   * @param origin Origin of the message.
   */
  static void warn(std::string message, std::string origin = EMPTY_ORIGIN);

  /**
   * Log an app-wide error message.
   *
   * @param message Message to log.
   * @param origin Origin of the message.
   */
  static void error(std::string message, std::string origin = EMPTY_ORIGIN);

  /**
   * Log an app-wide fatal message.
   *
   * @param message Message to log.
   * @param origin Origin of the message.
   */
  static void fatal(std::string message, std::string origin = EMPTY_ORIGIN);
};

/**
 * @brief Log emitter class, from which all log message emitters should inherit.
 */
class LogEmitter
{
private:
  std::string origin;

protected:
  LogEmitter(const std::string origin) : origin(origin) {}

  /**
   * Log a debug message.
   *
   * @param message Message to log.
   */
  void debug(std::string message);

  /**
   * Log an info message.
   *
   * @param message Message to log.
   */
  void info(std::string message);

  /**
   * Log a warning message.
   *
   * @param message Message to log.
   */
  void warn(std::string message);

  /**
   * Log an error message.
   *
   * @param message Message to log.
   */
  void error(std::string message);

  /**
   * Log a fatal message.
   *
   * @param message Message to log.
   */
  void fatal(std::string message);
};

#endif // LOGGER_HPP