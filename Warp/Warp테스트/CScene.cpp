#include "pch.h"
#include "CScene.h"
#include "CEnemy.h"

CScene::CScene()
{
	for (int i = static_cast<int>(OBJ_TYPE::START); i < static_cast<int>(OBJ_TYPE::END); ++i) {
		m_updateObjects.insert({ static_cast<OBJ_TYPE>(i), queue<CObject*>() });
		m_renderObjects.insert({ static_cast<OBJ_TYPE>(i), vector<CObject*>() });
	}

	m_updateObjects[OBJ_TYPE::PLAYER].push(new CPlayer());
	m_updateObjects[OBJ_TYPE::ENEMY].push(new CEnemy());

	m_camera = make_unique<CCamera>();
}

CScene::~CScene()
{
}

void CScene::Update(float elapsedTime)
{
	m_camera->Update();

	for (int i = static_cast<int>(OBJ_TYPE::START); i < static_cast<int>(OBJ_TYPE::END); ++i) {
		queue<CObject*>newxtUpdateQueue;
		while (!m_updateObjects[static_cast<OBJ_TYPE>(i)].empty()) {
			if (m_updateObjects[static_cast<OBJ_TYPE>(i)].front()->Update(elapsedTime)) {
				newxtUpdateQueue.push(m_updateObjects[static_cast<OBJ_TYPE>(i)].front());
			}
			m_updateObjects[static_cast<OBJ_TYPE>(i)].pop();
		}
		m_updateObjects[static_cast<OBJ_TYPE>(i)].swap(newxtUpdateQueue);
	}

	CObject* player = m_updateObjects[OBJ_TYPE::PLAYER].front();
	CObject* enemy = m_updateObjects[OBJ_TYPE::ENEMY].front();
	
	if (player->GetBoundingBox()->Intersect(*enemy->GetBoundingBox())) {
		cout << "Ãæµ¹" << endl;
	}
	
}

void CScene::Render()
{
	m_camera->Render();

	for (int i = static_cast<int>(OBJ_TYPE::START); i < static_cast<int>(OBJ_TYPE::END); ++i) {
		for (CObject* object : m_renderObjects[static_cast<OBJ_TYPE>(i)]) {
			object->Render(m_camera->GetViewMatrix(), m_camera->GetProjectionMatrix());
		}
	}	

	for (int i = static_cast<int>(OBJ_TYPE::START); i < static_cast<int>(OBJ_TYPE::END); ++i) {
		m_renderObjects[static_cast<OBJ_TYPE>(i)].clear();
	}
}
