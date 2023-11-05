#pragma once

struct MeshInfo
{
	vector<glm::vec3> vertex;
	vector<glm::vec3> color;
	vector<glm::vec3> normals;
	vector<glm::vec2> uvs;
	array<GLuint, 4> vbos;
};

class CMesh
{
public:
	static shared_ptr<MeshInfo> GetMeshInfo(const char* meshFileName, glm::vec3 color = { 0.0f, 0.0f, 0.0f });

private:
	static void LoadOBJ(const char* filename, vector<glm::vec3>& out_vertex, vector<glm::vec2>& out_uvs, vector<glm::vec3>& out_normals);

private:
	static unordered_map<string, shared_ptr<MeshInfo>> meshInfos;
};