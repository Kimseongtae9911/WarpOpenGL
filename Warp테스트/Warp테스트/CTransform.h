#pragma once
class CTransform
{
public:
	CTransform();
	~CTransform();

	const glm::vec3& GetPos() { return m_pos; }
	const glm::vec3& GetScale() { return m_scale; }
	const glm::vec3& GetRadian() { return m_rotateRadian; }
	const glm::mat4& GetWorldMatrix() { return m_worldMatrix; }

	void SetPos(const glm::vec3 pos) { m_pos = pos; }
	void SetScale(const glm::vec3 scale) { m_scale = scale; }
	void SetRadian(const glm::vec3 radian) { m_rotateRadian = radian; }

	void Update(const glm::vec3& moveAmount);

private:
	void Move(const glm::vec3& moveAmount);

private:
	glm::vec3 m_pos;
	glm::vec3 m_scale;
	glm::vec3 m_rotateRadian;
	glm::mat4 m_worldMatrix;
};

