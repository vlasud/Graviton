#include <core/filesystem.h>
#include <cassert>


void filesystem::read_file_content(const std::string& file_name, std::string& out)
{
	std::ifstream stream(file_name);
	out = std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
}

void filesystem::get_file_extension(const std::string& file_name, std::string& out)
{
	uint32_t dotIndex = file_name.find(".");
	assert(dotIndex >= 0);
	out = file_name.substr(dotIndex, file_name.length());
}