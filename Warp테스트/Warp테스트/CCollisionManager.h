#pragma once
class CCollisionManager
{
public:
	~CCollisionManager() {}
	static void CreateInstace();
	static CCollisionManager* GetInstace();

	bool CheckValidPos(const Vector2& pos, const Vector2& size);

private:
	CCollisionManager() {}
	
private:
	static unique_ptr<CCollisionManager>m_instance;
};

