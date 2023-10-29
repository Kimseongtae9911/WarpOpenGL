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
	//unique_ptr<CKeyInput> m_keyboard;	//����Ʈ������ ���� - �޸𸮴��� �߻��� ��x , shared_ptr�� �����ϱ⶧���� �Ű�����

	LARGE_INTEGER m_endTime;
	LARGE_INTEGER m_frequency;
	float m_elapsedTime;
};

