#pragma once
#include "CObject.h"
class CPlayer : public CObject
{
public:
	CPlayer();
	~CPlayer() override;	//������� �տ� virtual ��ӹ޾� �ڿ� override

	bool Update(float elapsedTime) override;
	void Render(const glm::mat4 view, const glm::mat4 proj) override;

private:
	Vector2 m_prevPos;
	high_resolution_clock::time_point m_lastFireTime;
};

