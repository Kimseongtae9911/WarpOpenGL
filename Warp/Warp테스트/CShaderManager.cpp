#include "pch.h"
#include "CShaderManager.h"
#include <fstream>

unique_ptr<CShaderManager> CShaderManager::m_instance;

CShaderManager::~CShaderManager()
{
    for (auto& [type, shader] : m_shaders) {
        glDeleteShader(shader);
    }
}

void CShaderManager::CreateInstance()
{
    m_instance.reset(new CShaderManager());
}

CShaderManager* CShaderManager::GetInstance()
{
    if (nullptr == m_instance)
        CreateInstance();

    return m_instance.get();
}

bool CShaderManager::AddShader(SHADER_TYPE type, const string& vertexFile, const string& fragmentFile)
{
    GLuint shader = glCreateProgram();

    string vsFile, fsFile;
    if (!ReadFile(vertexFile, vsFile)) {
        cerr << "에러: 버텍스 컴파일 실패\n";
        return false;
    }
    if (!ReadFile(fragmentFile, fsFile)) {
        cerr << "에러: 프래그먼트 컴파일 실패\n";
        return false;
    }

    if (!AttachShader(shader, vsFile.c_str(), 
        GL_VERTEX_SHADER)) {
        cerr << "에러: 버텍스 연결 실패\n";
        return false;
    }
    if (!AttachShader(shader, fsFile.c_str(),
        GL_FRAGMENT_SHADER)) {
        cerr << "에러: 프래그먼트 연결 실패\n";
        return false;
    }

    GLint success = 0;
    GLchar errorLog[1024] = { 0 };

    glLinkProgram(shader);

    glGetProgramiv(shader, GL_LINK_STATUS, &success);

    if (success == 0) {
        glGetProgramInfoLog(shader, sizeof(errorLog), NULL, errorLog);
        cout << vertexFile << ", " << fragmentFile << " Error linking shader program\n" << errorLog;
        assert(0);
        return false;
    }

    glValidateProgram(shader);
    glGetProgramiv(shader, GL_VALIDATE_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shader, sizeof(errorLog), NULL, errorLog);
        cout << vertexFile << ", " << fragmentFile << " Error validating shader program\n" << errorLog;
        assert(0);
        return false;
    }

    cout << vertexFile << ", " << fragmentFile << " Shader compiling is done.\n";

    m_shaders.insert({ type, shader });

    return true;
}

GLuint CShaderManager::UseShader(SHADER_TYPE type)
{
    if (!m_shaders.contains(type)) {
        cerr << "ERROR : Failed to find Shader\n";
        return -1;
    }

    glUseProgram(m_shaders[type]);

    return m_shaders[type];
}

bool CShaderManager::ReadFile(const string& filename, string& target)
{
    ifstream file(filename);

    if (file.fail()) {
        cerr << filename << " 로딩 실패\n";
        return false;
    }
    string line;
    while (getline(file, line)) {
        target.append(line.c_str());
        target.append("\n");
    }

    return true;
}

bool CShaderManager::AttachShader(GLuint shader, const char* shaderText, GLenum shaderType)
{
    GLuint shaderObject = glCreateShader(shaderType);

    if (shaderObject == 0) {
        return false;
    }

    const GLchar* p[1];
    p[0] = shaderText;
    GLint Lengths[1];
    Lengths[0] = strlen(shaderText);

    glShaderSource(shaderObject, 1, p, Lengths);
    glCompileShader(shaderObject);

    GLint success;
    glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &success);
    if (!success) {
        GLchar InfoLog[1024];

        glGetShaderInfoLog(shaderObject, 1024, NULL, InfoLog);
        fprintf(stderr, "Error compiling shader type %d: '%s'\n", shaderType, InfoLog);
        printf("%s \n", shaderText);
        return false;
    }

    glAttachShader(shader, shaderObject);

    return true;
}
