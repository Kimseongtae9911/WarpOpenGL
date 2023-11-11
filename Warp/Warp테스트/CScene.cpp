#include "pch.h"
#include "CScene.h"

CScene::CScene()
{
	for (int i = static_cast<int>(OBJ_TYPE::START); i < static_cast<int>(OBJ_TYPE::END); ++i) {
		m_updateObjects.insert({ static_cast<OBJ_TYPE>(i), queue<CObject*>() });
		m_renderObjects.insert({ static_cast<OBJ_TYPE>(i), vector<CObject*>() });
	}

	m_updateObjects[OBJ_TYPE::PLAYER].push(new CPlayer());

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
}

void CScene::Render()
{
	m_camera->Render();

	for (int i = static_cast<int>(OBJ_TYPE::START); i < static_cast<int>(OBJ_TYPE::END); ++i) {
		for (CObject* object : m_renderObjects[static_cast<OBJ_TYPE>(i)]) {
			object->Render();
		}
	}

	for (int i = static_cast<int>(OBJ_TYPE::START); i < static_cast<int>(OBJ_TYPE::END); ++i) {
		m_renderObjects[static_cast<OBJ_TYPE>(i)].clear();
	}
}
