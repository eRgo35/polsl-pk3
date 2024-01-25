#ifndef COLORS_HPP_INCLUDED
#define COLORS_HPP_INCLUDED

#include <iostream>

// this is a simple header file
// that contains all linux shell terminal colors
// used for formatting the output shell
// because i'm too lazy too setup an external library for that :p

std::string BLACK = "\033[0;30m";
std::string RED = "\033[1;31m";
std::string GREEN = "\033[1;32m";
std::string YELLOW = "\033[1;33m";
std::string BLUE = "\033[1;34m";
std::string MAGENTA = "\033[1;35m";
std::string CYAN = "\033[1;36m";
std::string LIGHT_GRAY = "\033[0;37m";
std::string DARK_GRAY = "\033[1;30m";
std::string BRIGHT_RED = "\033[0;31m";
std::string BRIGHT_GREEN = "\033[0;32m";
std::string BRIGHT_YELLOW = "\033[0;33m";
std::string BRIGHT_BLUE = "\033[0;34m";
std::string BRIGHT_MAGENTA = "\033[0;35m";
std::string BRIGHT_CYAN = "\033[0;36m";
std::string BOLD = "\033[1m";
std::string UNDERLINE = "\033[4m";
std::string REVERSE = "\033[7m";
std::string INVISIBLE = "\033[8m";
std::string RESET = "\033[0m";

#endif