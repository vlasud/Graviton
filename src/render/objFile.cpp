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

		// skip comments
		if (parts.front() == "#")
			continue;

		// vertex
		if (parts.front() == "v")
		{
			glm::vec3 vertex;
			vertex.x = (float)atof(parts[1].c_str());
			vertex.y = (float)atof(parts[2].c_str());
			vertex.z = (float)atof(parts[3].c_str());
			vertexes.push_back(vertex);
		}
		// indexes
		else if (parts.front() == "f")
		{
			std::vector<std::string> indexParts;
			utils::split_string(parts[1], '/', indexParts);
			indexes.push_back(atoi(indexParts.front().c_str()) - 1);
			utils::split_string(parts[2], '/', indexParts);
			indexes.push_back(atoi(indexParts.front().c_str()) - 1);
			utils::split_string(parts[3], '/', indexParts);
			indexes.push_back(atoi(indexParts.front().c_str()) - 1);
			utils::split_string(parts[4], '/', indexParts);
			indexes.push_back(atoi(indexParts.front().c_str()) - 1);
		}
	}

	stream.close();
}

ObjFile::~ObjFile()
{

}