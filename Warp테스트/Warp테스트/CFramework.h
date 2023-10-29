#pragma once
#include "CPlayer.h"

class CFramework
{
public:
	CFramework();
	~CFramework();

	void Update();
	void Render();
	void Keyboard(unsigned char key, int x, int y);

private:
	void FrameLimit(int fps);

private:
	//CObject* m_object;
	//unique_ptr<CKeyInput> m_keyboard;	//스마트포인터 장점 - 메모리누수 발생할 일x , shared_ptr은 공유하기때문에 신경써야함

	LARGE_INTEGER m_endTime;
	LARGE_INTEGER m_frequency;
	float m_elapsedTime;
};

