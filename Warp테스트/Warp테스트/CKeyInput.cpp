#include "pch.h"
#include "CKeyInput.h"

unique_ptr<CKeyInput> CKeyInput::m_instance;

void CKeyInput::CreateInstance()
{
	m_instance.reset(new CKeyInput());
}

CKeyInput* CKeyInput::GetInstance()
{
	if (nullptr == m_instance)
		CreateInstance();

	return m_instance.get();
}

void CKeyInput::Update()
{
	memset(m_keyBuffer, 0, sizeof(m_keyBuffer));
	DWORD pressedKey = 0;

	if (GetKeyboardState(m_keyBuffer)) {
		if (IsKeyPressed(key_code::W)) {
			pressedKey |= DIR_FORWARD;
		}
		if (IsKeyPressed(key_code::S)) {
			pressedKey |= DIR_BACKWARD;
		}
		if (IsKeyPressed(key_code::A)) {
			pressedKey |= DIR_LEFT;
		}
		if (IsKeyPressed(key_code::D)) {
			pressedKey |= DIR_RIGHT;
		}
		if (IsKeyPressed(key_code::SPACE)) {
			pressedKey |= FIRE_BULLET;
		}
	}

	m_keyInput = pressedKey;
}

bool CKeyInput::IsKeyPressed(DWORD key)
{
	if (m_keyBuffer[key] & 0x80)
		return true;

	return false;
}
