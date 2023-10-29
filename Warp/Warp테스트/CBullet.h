#pragma once
#include "CObject.h"
class CBullet : public CObject
{
public:
	CBullet(const Vector2& pos, const Vector2& dir);
	~CBullet() override;	//override - 같은 메모리를 두번 해제할수있어서 bullet의 소멸자만 해제하려고

	bool Update(float elapsedTime) override;
	void Render() override;
};