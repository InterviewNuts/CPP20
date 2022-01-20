/**
 * @file std_source_location.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-01-20
 *
 * @copyright Copyright (c) 2022
 *
 */
/*
C++11 has two macros for __LINE__ and __FILE__ to get the information when the macros are used.
 With C++20, the class source_location gives you the file name, the line number, column number,
 and function name about the source code. The short example from cppreference.com shows
 the first usage:

*/
#include <iostream>
#include <string_view>
#include <source_location>

void log(std::string_view message, const std::source_location &location = std::source_location::current())
{
    std::cout << "info:"
              << location.file_name() << ":"
              << location.line() << " "
              << message << '\n';
}

int main()
{
    log("Hello world!"); // info:main.cpp:15 Hello world!
}