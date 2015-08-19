#include "util/read-file.h"


Optional<std::vector<char>> readFile(const char* path)
{
	FILE* fin = fopen(path, "rb");
	std::vector<char> result;
	while (ferror(fin) == 0)
	{
		int c = fgetc(fin);
		if (c == EOF)
			break;
		result.push_back(static_cast<char>(c));
	}
	
	if (ferror(fin) != 0)
		return NullOpt;
	else
		return result;
}