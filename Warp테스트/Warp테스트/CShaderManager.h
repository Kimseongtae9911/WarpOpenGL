#pragma once
class CShaderManager
{
public:
	~CShaderManager();
	static void CreateInstance();
	static CShaderManager* GetInstance();

	bool AddShader(SHADER_TYPE type, 
		const string& vertexFile, 
		const string& fragmentFile);

	GLuint UseShader(SHADER_TYPE type);

private:
	CShaderManager() {}

	bool ReadFile(const string& filename,
		string& target);
	bool AttachShader(GLuint shader,
		const char* shaderText, GLenum shaderType);

private:
	static unique_ptr<CShaderManager> m_instance;
	unordered_map<SHADER_TYPE, GLuint> m_shaders;
};