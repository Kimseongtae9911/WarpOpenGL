#pragma once
#include "CObject.h"
class CBullet : public CObject
{
public:
	CBullet(const glm::vec3& pos, const Vector2& dir);
	~CBullet() override;	//override - ���� �޸𸮸� �ι� �����Ҽ��־ bullet�� �Ҹ��ڸ� �����Ϸ���

	bool Update(float elapsedTime) override;
	void Render(const glm::mat4 view, const glm::mat4 proj) override;
};