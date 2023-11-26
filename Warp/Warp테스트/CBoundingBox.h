#pragma once

class CBoundingBox
{
public:
	CBoundingBox() : m_min(glm::vec3(0.0f)), m_max(glm::vec3(0.0f)) {}

	void CreateBoundingBox(const std::vector<glm::vec3>& vertices);

	bool Intersect(const CBoundingBox& other) const;
	
	vector<glm::vec3> GetCorners() const;

	glm::vec3 GetMin() const { 
		glm::vec4 result =  m_matrix * glm::vec4(m_min, 1.0f);
		return glm::vec3(result);
	}
	glm::vec3 GetMax() const { 
		glm::vec4 result = m_matrix * glm::vec4(m_max, 1.0f);
		return glm::vec3(result);
	}

	void Render(const glm::mat4& modelMatrix, const glm::mat4& view, const glm::mat4& proj);

private:
	glm::vec3 m_min;
	glm::vec3 m_max;
	GLuint m_vbo;
	glm::mat4 m_matrix;
};

