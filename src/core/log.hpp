#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <colors.hpp>
#include <source_location.hpp>

#define ENUM_TO_STRING(e) #e

#ifndef BOLT_LOG_FILE
#define BOLT_LOG_FILE "../../log"
#endif

#define LOG_ERROR(msg) LogUtil::log(LogType::ERROR, msg)

#ifndef NDEBUG
#define MSG_DEBUG(msg_dbg) COLOR(GREEN_FG, BLACK_BG) std::cout << "DEBUG: " << msg_dbg << std::endl;
#define MSG_ERROR(msg_err) COLOR(RED_FG, BLACK_BG) std::cout << "ERROR: " << msg_err << std::endl;

#define LOG_WARNING(msg) LogUtil::log(LogType::WARNING, msg)
#define LOG(msg) LogUtil::log(LogType::INFO, msg)
#else
#define MSG_DEBUG(string) {}
#define MSG_ERROR(bolt_msg_err) {}

#define LOG_WARNING(msg) {}
#define LOG(msg) {}
#endif

enum LogType {
    INFO,
    WARNING,
    ERROR
};

class LogUtil {
public:
    LogUtil() = delete;

    LogUtil(const LogUtil &) = delete;

    static void initLogs();

    static void log(LogType, const std::string &, source_location s = source_location::current());

public:
    static time_t raw_time;
    static std::string file_loc;
};