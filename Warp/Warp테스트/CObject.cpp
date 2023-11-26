#include "pch.h"
#include "CObject.h"
#include "CShaderManager.h"

constexpr float PLAYER_SPEED = 1.f;

CObject::CObject()
{
	m_transform = new CTransform();
	m_boundingBox = new CBoundingBox();
}

CObject::~CObject()
{
	for (auto& vbo : m_mesh->vbos) {
		glDeleteBuffers(1, &vbo);
	}

	delete m_transform;
	delete m_boundingBox;
}

bool CObject::Update(float elapsedTime)
{
	Vector2 moveAmount = m_dir * elapsedTime * m_speed;
	m_transform->Update(glm::vec3(moveAmount.x, 0.f, -moveAmount.y));
	m_boundingBox->Update(m_transform->GetPos());
	return true;
}

void CObject::Render(const glm::mat4 view, const glm::mat4 proj)
{
	GLuint program = CShaderManager::GetInstance()->UseShader(SHADER_TYPE::DEFAULT);

	glUniformMatrix4fv(glGetUniformLocation(program, "modelTransform"), 1, GL_FALSE, glm::value_ptr(m_transform->GetWorldMatrix()));

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
