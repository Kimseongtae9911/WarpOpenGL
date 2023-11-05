#include "pch.h"
#include "CCamera.h"
#include "CShaderManager.h"

constexpr float FRUSTUM_NEAR = 0.1f;
constexpr float FRUSTUM_FAR = 200.f;
constexpr float FRUSTUM_FOVY = 45.f;

CCamera::CCamera()
{
	m_pos = { 0.0f, 1.0f, 5.0f };
	m_lookAt = { 0.0f, 0.0f, 0.0f };
	m_up = { 0.0f, 1.0f, 0.0f };
	m_viewMatrix = glm::mat4(1.0f);
}

CCamera::~CCamera()
{
}

void CCamera::Update()
{
	m_viewMatrix = glm::lookAt(m_pos, m_lookAt, m_up);
	m_projectMatrix = glm::perspective(glm::radians(FRUSTUM_FOVY), static_cast<float>(WINDOW_WIDTH) / static_cast<float>(WINDOW_HEIGHT), FRUSTUM_NEAR, FRUSTUM_FAR);
}

void CCamera::Render()
{
	GLuint program = CShaderManager::GetInstance()->UseShader(SHADER_TYPE::DEFAULT);

	glUniformMatrix4fv(glGetUniformLocation(program, "viewTransform"), 1, GL_FALSE, glm::value_ptr(m_viewMatrix));
	glUniformMatrix4fv(glGetUniformLocation(program, "projectionTransform"), 1, GL_FALSE, value_ptr(m_projectMatrix));
}
