#pragma once
#include <vector>
#include <string>
namespace tools{
	namespace string{
		std::vector<std::string> explode(std::string string, char delim);
		std::string remove(std::string stringIn,const char toRemove[]);
	}

}

