#pragma once

class CCamera
{
public:
	CCamera();
	~CCamera();

	const glm::mat4& GetViewMatrix() const { return m_viewMatrix; }
	const glm::mat4& GetProjectionMatrix() const { return m_projectMatrix; }
	void Update();
	void Render();

private:
	glm::vec3 m_pos;
	glm::vec3 m_lookAt;
	glm::vec3 m_up;

	glm::mat4 m_viewMatrix;
	glm::mat4 m_projectMatrix;
};

