#pragma once
#include "CPlayer.h"
#include "CCamera.h"

class CScene
{
public:
	CScene();
	~CScene();

	void Update(float elapsedTime);
	void Render();

	void AddUpdateObj(OBJ_TYPE type, CObject* obj) { m_updateObjects[type].push(obj); }
	void AddRenderObj(OBJ_TYPE type, CObject* obj) { m_renderObjects[type].push_back(obj); }

private:
	unordered_map<OBJ_TYPE, queue<CObject*>> m_updateObjects;
	unordered_map<OBJ_TYPE, vector<CObject*>> m_renderObjects;

	unique_ptr<CCamera> m_camera;
};

