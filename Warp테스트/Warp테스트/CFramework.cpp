#include "pch.h"
#include "CFramework.h"
#include "CKeyInput.h"
#include "CSceneManager.h"

CFramework::CFramework()
{
	//m_object = new CPlayer();
	//m_keyboard = make_unique<CKeyInput>();
	CSceneManager::CreateInstance();
	CSceneManager::GetInstance()->Initialize();
	QueryPerformanceFrequency(&m_frequency);	
	QueryPerformanceCounter(&m_endTime);
}

CFramework::~CFramework()
{
}

void CFramework::Update()
{
	FrameLimit(60);

	CKeyInput::GetInstance()->Update();
	//m_object->Update(m_elapsedTime);
	CSceneManager::GetInstance()->Update(m_elapsedTime);
}

void CFramework::Render()
{
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	//m_object->Render();
	CSceneManager::GetInstance()->Render();

	glutSwapBuffers();
}

void CFramework::Keyboard(unsigned char key, int x, int y)
{
}

void CFramework::FrameLimit(int fps)
{
	LARGE_INTEGER currentTime;
	QueryPerformanceCounter(&currentTime);

	m_elapsedTime = static_cast<float>(currentTime.QuadPart - m_endTime.QuadPart) / m_frequency.QuadPart;

	float targetElapsedTime = 1.0f / static_cast<float>(fps);
	float remainingTime = targetElapsedTime - m_elapsedTime;
	
	while (remainingTime > 0.f)
	{
		QueryPerformanceCounter(&currentTime);
		m_elapsedTime = static_cast<float>(currentTime.QuadPart - m_endTime.QuadPart) / m_frequency.QuadPart;
		remainingTime = targetElapsedTime - m_elapsedTime;
	}

	QueryPerformanceCounter(&m_endTime);
}
