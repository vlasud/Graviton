#include <core/filesystem.h>
#include <utils/stringUtils.h>
#include <cassert>


void filesystem::read_file_content(const std::string& file_name, std::string& out)
{
	std::ifstream stream(file_name);
	assert(!stream.fail());
	out = std::string(std::istreambuf_iterator<char>(stream), std::istreambuf_iterator<char>());
	stream.close();
}

void filesystem::get_file_extension(const std::string& file_name, std::string& out)
{
	std::vector<std::string> parts;
	utils::split_string(file_name, '.', parts);
	assert(parts.size() >= 2);
	out = parts.back();
}

bool filesystem::check_file_extension(const std::string& file_name, const std::string& extension)
{
	std::string fileExtension;
	get_file_extension(file_name, fileExtension);
	return fileExtension == extension;
}