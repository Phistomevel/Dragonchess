#include "String.h"

namespace tools {
	namespace string {
		std::vector<std::string> explode(std::string string, char delim) {
			std::vector<std::string> ret;
			while (string.find(delim)!=string.npos) {
				ret.push_back(string.substr(0,string.find(delim)));
				string = string.substr(string.find(delim)+1);
			}
			ret.push_back(string.substr(0, string.find(delim)));
			return ret;
		}
		std::string remove(std::string stringIn,const char toRemove[]) {
			while (stringIn.find(toRemove) != stringIn.npos) {
				stringIn.erase(stringIn.find(toRemove),1);
			}
			return stringIn;
		}

	}

}