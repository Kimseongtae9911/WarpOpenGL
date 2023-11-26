#include "pch.h"
#include "CEnemy.h"
#include "CSceneManager.h"

CEnemy::CEnemy()
{
	m_transform->SetPos(glm::vec3(0.5f, 0.5f, 0.5f));

	m_mesh = CMesh::GetMeshInfo("sphere.obj", glm::vec3(0.0f, 1.0f, 0.0f));

	glGenBuffers(1, &m_mesh->vbos[0]);
	glBindBuffer(GL_ARRAY_BUFFER, m_mesh->vbos[0]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_mesh->vertex.size(), m_mesh->vertex.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &m_mesh->vbos[1]);
	glBindBuffer(GL_ARRAY_BUFFER, m_mesh->vbos[1]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_mesh->color.size(), m_mesh->color.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &m_mesh->vbos[2]);
	glBindBuffer(GL_ARRAY_BUFFER, m_mesh->vbos[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * m_mesh->normals.size(), m_mesh->normals.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &m_mesh->vbos[3]);
	glBindBuffer(GL_ARRAY_BUFFER, m_mesh->vbos[3]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec2) * m_mesh->uvs.size(), m_mesh->uvs.data(), GL_STATIC_DRAW);
}

CEnemy::~CEnemy()
{
	
}

bool CEnemy::Update(float elapsedTime)
{
	CSceneManager::GetInstance()->AddRenderObj(OBJ_TYPE::PLAYER, this);

	return true;
}

void CEnemy::Render(const glm::mat4 view, const glm::mat4 proj)
{
	CObject::Render(view, proj);
}
