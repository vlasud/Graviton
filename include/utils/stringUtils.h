#pragma once

#include <string>
#include <vector>

namespace utils
{
    void split_string(const std::string& str, char delim, std::vector<std::string>& elems);
};