#include "wrapper.hpp"
#include "whereami.h"

namespace wai
{
	std::filesystem::path getExecutablePath()
	{
		int dirPathLength;
		int pathLength = wai_getExecutablePath(NULL, 0, NULL);
		char* path = new char[pathLength + 1];
		wai_getExecutablePath(path, pathLength, &dirPathLength);
		path[dirPathLength] = '\0';
		return std::filesystem::path{path};
	}
}
