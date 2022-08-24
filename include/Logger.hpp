#pragma once

#include <iostream>

class Logger
{
public:
    static void Debug(const char* msg)
    {
        std::cerr << "[DEBUG]: ";
        std::cerr << msg << std::endl;
    }

    static void Error(const char* msg)
    {
        std::cerr << "[ERROR]: ";
        std::cerr << msg << std::endl;
    }
};