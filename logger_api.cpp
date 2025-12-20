#include "logger_api.h"
#include "logger.hpp"

int logger_init(const char* logs_dir, int use_local_time) {
    return Logger::instance().initialize(logs_dir, use_local_time);
}

int logger_log_info(const char* msg) {
    return Logger::instance().logInfo(msg);
}

int logger_log_error(const char* msg) {
    return Logger::instance().logError(msg);
}

int logger_log_warning(const char* msg) {
    return Logger::instance().logWarning(msg);
}

void logger_shutdown(void) {}

