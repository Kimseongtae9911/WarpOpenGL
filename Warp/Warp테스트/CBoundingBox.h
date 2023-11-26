#pragma once

class CBoundingBox
{
public:
	CBoundingBox() : m_min(glm::vec3(0.0f)), m_max(glm::vec3(0.0f)) {}

	void CreateBoundingBox(const std::vector<glm::vec3>& vertices);

	bool Intersect(const CBoundingBox& other) const;
	
	vector<glm::vec3> GetCorners() const;

	const glm::vec3& GetMin() const { return m_min; }
	const glm::vec3& GetMax() const { return m_max; }

	void Update(const glm::vec3& pos);
	void Render(const glm::mat4& modelMatrix, const glm::mat4& view, const glm::mat4& proj);

private:
	glm::vec3 m_min;
	glm::vec3 m_max;
	glm::vec3 m_pos;
	GLuint m_vbo;
};

