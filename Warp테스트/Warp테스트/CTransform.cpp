#include "pch.h"
#include "CTransform.h"

CTransform::CTransform()
{
	m_worldMatrix = glm::mat4(1.0f);
	m_scale = { 1.0f, 1.0f, 1.0f };
}

CTransform::~CTransform()
{
}

void CTransform::Update(const glm::vec3& moveAmount)
{
	Move(moveAmount);
	m_worldMatrix *= glm::scale(glm::mat4(1.0f), m_scale);
}

void CTransform::Move(const glm::vec3& moveAmount)
{
	m_pos += moveAmount;	
	m_worldMatrix = glm::translate(glm::mat4(1.0f), m_pos);
}
