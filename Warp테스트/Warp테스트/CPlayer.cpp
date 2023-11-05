#include "pch.h"
#include "CPlayer.h"
#include "CCollisionManager.h"
#include "CKeyInput.h"
#include "CSceneManager.h"
#include "CBullet.h"

constexpr float PLAYER_SIZE = 0.5f;
constexpr float PLAYER_SPEED = 1.f;
constexpr int BULLET_COOLTIME = 100; //ms

CPlayer::CPlayer()
{
	m_transform->SetPos(glm::vec3(0.5f, 0.5f, 0.0f));
	m_speed = PLAYER_SPEED;

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

CPlayer::~CPlayer()
{
}

bool CPlayer::Update(float elapsedTime)
{
	DWORD keyInput = CKeyInput::GetInstance()->GetKeyInput();

	if (keyInput) {
		if (keyInput & DIR_FORWARD)
			SetDir({ 0,1 });
		if (keyInput & DIR_BACKWARD)
			SetDir({ 0,-1 });
		if (keyInput & DIR_LEFT)
			SetDir({ -1,0 });
		if (keyInput & DIR_RIGHT)
			SetDir({ 1,0 });
		if (keyInput & FIRE_BULLET) {
			if (high_resolution_clock::now() - m_lastFireTime >= milliseconds(BULLET_COOLTIME)) {
				CSceneManager::GetInstance()->AddUpdateObj(OBJ_TYPE::BULLET, new CBullet(m_transform->GetPos(), m_dir));
				m_lastFireTime = high_resolution_clock::now();
			}
		}
			
	}
	//m_prevPos = m_pos;

	CObject::Update(elapsedTime);

	//if (!CCollisionManager::GetInstace()->CheckValidPos(m_pos, m_size)) {
	//	m_pos = m_prevPos;
	//}

	CSceneManager::GetInstance()->AddRenderObj(OBJ_TYPE::PLAYER, this);
	m_dir.x = m_dir.y = 0.f;

	return true;
}

void CPlayer::Render()
{
	CObject::Render();
}
