#pragma once
#include"CScene.h"

class CSceneManager
{
public:
	~CSceneManager();
	static void CreateInstance();
	static CSceneManager* GetInstance();

	void Initialize();
	void Update(float elapsedTime);
	void Render();

	void AddUpdateObj(OBJ_TYPE type, CObject* obj) { m_scene->AddUpdateObj(type, obj); }
	void AddRenderObj(OBJ_TYPE type, CObject* obj) { m_scene->AddRenderObj(type, obj); }

private:
	CSceneManager(){}

private:
	static unique_ptr<CSceneManager> m_instance;
	CScene* m_scene;
};

