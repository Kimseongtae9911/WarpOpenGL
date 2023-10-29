#pragma once
namespace key_code {
	inline DWORD A = 0x41, D = 0x44, S = 0x53, W = 0x57, SPACE = VK_SPACE;
}
//enum °øºÎÇÏÀð
class CKeyInput
{
public:
	~CKeyInput() {}

	static void CreateInstance();
	static CKeyInput* GetInstance();
	
	void Update();

	const DWORD GetKeyInput() const { return m_keyInput; }

private:
	CKeyInput() {}

	bool IsKeyPressed(DWORD key);

private:
	static unique_ptr<CKeyInput> m_instance;
	BYTE m_keyBuffer[256];
	DWORD m_keyInput;
};

