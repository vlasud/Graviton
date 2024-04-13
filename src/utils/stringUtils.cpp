#include <utils/stringUtils.h>
#include <sstream>


void utils::split_string(const std::string& str, char delim, std::vector<std::string>& elems)
{
    elems.clear();
    std::stringstream ss(str);
    std::string part;
    while (std::getline(ss, part, delim))
        elems.push_back(part);
}