#pragma once

#include <filesystem>
#include <fstream>
#include <string>

namespace filesystem
{
	void read_file_content(const std::string& file_name, std::string& out);
	void get_file_extension(const std::string& file_name, std::string& out);
	bool check_file_extension(const std::string& file_name, const std::string& extension);
}