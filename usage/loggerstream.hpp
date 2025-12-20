#ifndef LOGGERSTREAM_HPP
#define LOGGERSTREAM_HPP

#include <sstream>
#include <string>
#include "logger.h"

class LoggerStream {
 public:
  using LogFunc = int (*)(const char*);

  explicit LoggerStream(LogFunc fn)
      : m_fn(fn) {}

  ~LoggerStream() {
    const std::string s = m_buffer.str();
    if (!s.empty()) {
      m_fn(s.c_str());
    }
  }

  template <typename T>
  LoggerStream& operator<<(const T& value) {
    m_buffer << value;
    return *this;
  }

 private:
  std::ostringstream m_buffer;
  LogFunc m_fn;
};

#define linfo    LoggerStream(logger_log_info)
#define lerror   LoggerStream(logger_log_error)
#define lwarning LoggerStream(logger_log_warning)

#endif

