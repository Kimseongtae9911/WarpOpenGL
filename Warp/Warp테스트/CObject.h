#pragma once

struct Mesh
{
	vector<glm::vec3> vertex;
	vector<glm::vec3> color;
	array<GLuint, 2> vbos;
};

class CObject
{
public:
	CObject();
	virtual ~CObject();

	virtual bool Update(float elapsedTime);
	virtual void Render();

	void SetDir(const Vector2& dir);

protected:
	Vector2 m_pos;	//사각형의 정가운데
	Vector2 m_dir;	//방향
	Vector2 m_size;
	float m_speed;

	Mesh* m_mesh;
};

