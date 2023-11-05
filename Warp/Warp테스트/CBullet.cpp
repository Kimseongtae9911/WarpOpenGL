#include "pch.h"
#include "CBullet.h"
#include "CCollisionManager.h"
#include "CSceneManager.h"

constexpr float BULLET_SIZE = 0.1f;
constexpr float BULLET_SPEED = 5.0f;

CBullet::CBullet(const glm::vec3& pos, const Vector2& dir)
{
	m_transform->SetPos(pos);
	m_dir = dir;
	m_speed = BULLET_SPEED;

	m_mesh = CMesh::GetMeshInfo("cube.obj", glm::vec3(1.0f, 0.0f, 0.0f));

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

CBullet::~CBullet()
{
}

bool CBullet::Update(float elapsedTime)
{
	CObject::Update(elapsedTime);
	//if (!CCollisionManager::GetInstace()->CheckValidPos(m_pos, m_size)) {
	//	delete this;
	//	return false;
	//}
	//else {
		CSceneManager::GetInstance()->AddRenderObj(OBJ_TYPE::BULLET, this);
		return true;
	//}
}

void CBullet::Render()
{
	CObject::Render();
}
