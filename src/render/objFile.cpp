#include <render/objFile.h>
#include <core/filesystem.h>
#include <utils/stringUtils.h>
#include <sstream>
#include <cassert>

ObjFile::ObjFile(const std::string& path_to_file)
{
	assert(filesystem::check_file_extension(path_to_file, "obj"));
	std::ifstream stream(path_to_file);
	assert(!stream.fail());
	std::string line;
	std::vector<std::string> parts;
	while (std::getline(stream, line))
	{
		utils::split_string(line, ' ', parts);
		if (parts.front() == "#")
			continue;

		// vertex
		if (parts.front() == "v")
		{

		}
	}
	stream.close();
}

ObjFile::~ObjFile()
{

}