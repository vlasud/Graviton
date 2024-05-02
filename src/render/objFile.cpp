#include <render/objFile.h>
#include <core/filesystem.h>
#include <utils/stringUtils.h>
#include <fstream>


ObjFile::ObjFile(const std::string& path_to_file)
{
    if (!filesystem::check_file_extension(path_to_file, "obj"))
    {
        // TODO: handle
        return;
    }

    std::ifstream stream(path_to_file);
    if (stream.fail())
    {
        // TODO: handle
        return;
    }

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
            for (int i = 1; i <= 3; ++i)
                v.push_back((float)atof(parts[i].c_str()));

        // vertex texture pos
        if (parts.front() == "vt")
            for (int i = 1; i <= 2; ++i)
                vt.push_back((float)atof(parts[i].c_str()));

        // indexes
        else if (parts.front() == "f")
        {
            std::vector<std::string> indexParts;
            for (int i = 1; i < parts.size(); ++i)
            {
                utils::split_string(parts[i], '/', indexParts);
                fv.push_back(atoi(indexParts.front().c_str()) - 1);
            }
        }
    }

    stream.close();
}

ObjFile::~ObjFile()
{
}