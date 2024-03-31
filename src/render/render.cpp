#include <render/render.h>
#include <render/shaders.h>

#include <glad/gl.h>
#include <vector>
#include <filesystem>
#include <fstream>
#include <cassert>


std::vector<ShaderProgram> shaderProgramPool;


static inline void prepare_render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void engine_render_act(double deltaTime)
{
    prepare_render();

    for (auto& i : shaderProgramPool)
        glUseProgram(i.id);
}


static bool read_shader_file(const std::string& path, std::string& out)
{
    std::ifstream stream(path);
    if (!stream.is_open())
        return false;
    std::ostringstream ss;
    ss << stream.rdbuf();
    out = ss.str();
    return true;
}


void engine_load_shaders(const std::string& shaders_path)
{
    assert(std::filesystem::exists(shaders_path));

    for (auto& i : std::filesystem::directory_iterator(shaders_path))
    {
        const std::string fileName = i.path().string();
        std::string ext = fileName.substr(fileName.find("."), fileName.length());
        auto shaderType = ext == ".vrtx" ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER;

        Shader shader;
        shader.id = glCreateShader(shaderType);

        std::string source;
        if (!read_shader_file(fileName, source))
            continue;

        const char* c_source = source.c_str();
        glShaderSource(shader.id, 1, &c_source, nullptr);
        glCompileShader(shader.id);

        GLint result;
        glGetShaderiv(shader.id, GL_COMPILE_STATUS, &result);
        assert(result == GL_TRUE);

        ShaderProgram program;
        program.id = glCreateProgram();
        shaderProgramPool.push_back(program);

        glAttachShader(program.id, shader.id);
        glLinkProgram(program.id);
        glValidateProgram(program.id);

        glDeleteShader(shader.id);
    }
}