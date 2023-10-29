#include "pch.h"
#include "CSceneManager.h"

unique_ptr<CSceneManager> CSceneManager::m_instance;

CSceneManager::~CSceneManager()
{
	delete m_scene;
}

void CSceneManager::CreateInstance()
{
	m_instance.reset(new CSceneManager());
}

CSceneManager* CSceneManager::GetInstance()
{
	if (nullptr == m_instance)
		CreateInstance();

	return m_instance.get();
}

void CSceneManager::Initialize()
{
	m_scene = new CScene();
}

void CSceneManager::Update(float elapsedTime)
{
	m_scene->Update(elapsedTime);
}

void CSceneManager::Render()
{
	m_scene->Render();
}
