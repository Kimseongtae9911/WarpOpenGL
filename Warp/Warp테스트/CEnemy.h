#pragma once
#include "CObject.h"

class CEnemy : public CObject
{
public:
	CEnemy();
	~CEnemy() override;

	bool Update(float elapsedTime) override;
	void Render(const glm::mat4 view, const glm::mat4 proj) override;
};

