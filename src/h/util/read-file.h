#ifndef UTIL_READFILE_INCL
#define UTIL_READFILE_INCL

#include <stdio.h>
#include <vector>
#include <string>
#include "util/optional.h"

Optional<std::vector<char>> readFile(const std::string& path);

#endif