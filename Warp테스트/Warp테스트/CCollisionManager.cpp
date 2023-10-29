#include "pch.h"
#include "CCollisionManager.h"

unique_ptr<CCollisionManager> CCollisionManager::m_instance;


void CCollisionManager::CreateInstace()
{
	m_instance.reset(new CCollisionManager());
}

CCollisionManager* CCollisionManager::GetInstace()
{
	if (nullptr == m_instance)
		CreateInstace();

	return m_instance.get();
}

bool CCollisionManager::CheckValidPos(const Vector2& pos, const Vector2& size)
{
	if (pos.x - (size.x / 2.f) < -1.f || pos.x + (size.x / 2.f) > 1.f)
		return false;
	if (pos.y - (size.y / 2.f) < -1.f || pos.y + (size.y / 2.f) > 1.f)
		return false;

	return true;
}
