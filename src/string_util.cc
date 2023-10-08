#include "cpputil/string_util.h"

#include <sstream>
#include <algorithm>

std::vector<std::string> split(std::string const& in_string, char delimiter)
{
    std::vector<std::string> result {};
    std::stringstream ss (in_string);
    std::string item {};
    
    while (getline (ss, item, delimiter)) {
        result.push_back (item);
    }

    result.erase(std::remove(result.begin(), result.end(), ""),
               result.end());
    
    return result;
}
