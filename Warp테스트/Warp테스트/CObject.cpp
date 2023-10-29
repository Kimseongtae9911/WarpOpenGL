#include "pch.h"
#include "CObject.h"
#include "CShaderManager.h"

constexpr float PLAYER_SPEED = 1.f;

CObject::CObject()
{
	m_pos.x = m_pos.y = 0.5f;

	m_mesh = new Mesh();
}

CObject::~CObject()
{
	for (auto& vbo : m_mesh->vbos) {
		glDeleteBuffers(1, &vbo);
	}

	delete m_mesh;
}

bool CObject::Update(float elapsedTime)
{
	m_pos += m_dir * elapsedTime * m_speed;

	return true;
}

void CObject::Render()
{
	GLuint program = CShaderManager::GetInstance()->UseShader(SHADER_TYPE::DEFAULT);

	GLuint moveLocation = 
		glGetUniformLocation(program, "movePos");
	glUniform2f(moveLocation, m_pos.x, m_pos.y);

	for (int i = 0; i < m_mesh->vbos.size(); ++i) {
		glEnableVertexAttribArray(i);
		glBindBuffer(GL_ARRAY_BUFFER, m_mesh->vbos[i]);
		glVertexAttribPointer(i, 3, GL_FLOAT, GL_FALSE, 0, 0);
	}

	glDrawArrays(GL_TRIANGLES, 0, m_mesh->vertex.size());

	for (int i = 0; i < m_mesh->vbos.size(); ++i) {
		glDisableVertexAttribArray(i);
	}
}

void CObject::SetDir(const Vector2& dir)
{
	if (IsfloatEqual(dir.x, 1.f) && IsfloatEqual(m_dir.x, 1.f))
		return;
	if (IsfloatEqual(dir.x, -1.f) && IsfloatEqual(m_dir.x, -1.f))
		return;
	if (IsfloatEqual(dir.y, 1.f) && IsfloatEqual(m_dir.y, 1.f))
		return;
	if (IsfloatEqual(dir.y, -1.f) && IsfloatEqual(m_dir.y, -1.f))
		return;

	m_dir += dir;
}
