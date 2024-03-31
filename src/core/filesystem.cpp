#include <core/filesystem.h>


void filesystem::read_file_content(const std::string& file_name, std::string& out)
{
	std::ifstream stream(file_name);
	out = std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
}