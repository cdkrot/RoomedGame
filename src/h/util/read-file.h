#ifndef UTIL_READFILE_INCL
#define UTIL_READFILE_INCL

#include <stdio.h>
#include <vector>
#include "util/optional.h"

Optional<std::vector<char>> readFile(const char* path);

#endif