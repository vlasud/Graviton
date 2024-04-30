#pragma once

#include <render/renderer.h>
#include <string>
#include <vector>

struct ObjFile
{
    std::vector<float> v;
    std::vector<float> vn;
    std::vector<float> vt;
    std::vector<uint32_t> fv;

    ObjFile(const std::string &path_to_file);
    ~ObjFile();
};