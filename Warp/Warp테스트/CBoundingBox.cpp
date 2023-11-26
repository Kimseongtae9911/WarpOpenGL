#include "pch.h"
#include "CBoundingBox.h"
#include "CShaderManager.h"

void CBoundingBox::CreateBoundingBox(const std::vector<glm::vec3>& vertices)
{
    m_min = m_max = vertices[0];

    for (const auto& vertex : vertices) {
        m_min = glm::min(m_min, vertex);    //m_min과 vertex 중 더 작은 값 반환
        m_max = glm::max(m_max, vertex);    //m_max과 vertex 중 더 큰 값 반환
    }

    glGenBuffers(1, &m_vbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * GetCorners().size(), GetCorners().data(), GL_STATIC_DRAW);
}

bool CBoundingBox::Intersect(const CBoundingBox& other) const
{
    return !(GetMax().x < other.GetMin().x || GetMin().x > other.GetMax().x ||
            GetMax().y < other.GetMin().y || GetMin().y > other.GetMax().y ||
            GetMax().z < other.GetMin().z || GetMin().z > other.GetMax().z);
}

vector<glm::vec3> CBoundingBox::GetCorners() const
{
    std::vector<glm::vec3> corners;
    //bottom
    corners.push_back(glm::vec3(m_min.x, m_min.y, m_min.z));
    corners.push_back(glm::vec3(m_min.x, m_min.y, m_max.z));
    corners.push_back(glm::vec3(m_max.x, m_min.y, m_max.z));
    corners.push_back(glm::vec3(m_max.x, m_min.y, m_min.z));

    //top
    corners.push_back(glm::vec3(m_min.x, m_max.y, m_min.z));
    corners.push_back(glm::vec3(m_min.x, m_max.y, m_max.z));
    corners.push_back(glm::vec3(m_max.x, m_max.y, m_max.z));
    corners.push_back(glm::vec3(m_max.x, m_max.y, m_min.z));

    //left
    corners.push_back(glm::vec3(m_min.x, m_min.y, m_min.z));
    corners.push_back(glm::vec3(m_min.x, m_min.y, m_max.z));
    corners.push_back(glm::vec3(m_min.x, m_max.y, m_max.z));
    corners.push_back(glm::vec3(m_min.x, m_max.y, m_min.z));

    //right
    corners.push_back(glm::vec3(m_max.x, m_min.y, m_max.z));
    corners.push_back(glm::vec3(m_max.x, m_min.y, m_min.z));
    corners.push_back(glm::vec3(m_max.x, m_max.y, m_min.z));
    corners.push_back(glm::vec3(m_max.x, m_max.y, m_max.z));

    //front
    corners.push_back(glm::vec3(m_max.x, m_max.y, m_max.z));
    corners.push_back(glm::vec3(m_min.x, m_max.y, m_max.z));
    corners.push_back(glm::vec3(m_min.x, m_min.y, m_max.z));
    corners.push_back(glm::vec3(m_max.x, m_min.y, m_max.z));

    //back
    corners.push_back(glm::vec3(m_max.x, m_min.y, m_min.z));
    corners.push_back(glm::vec3(m_min.x, m_min.y, m_min.z));
    corners.push_back(glm::vec3(m_min.x, m_max.y, m_min.z));
    corners.push_back(glm::vec3(m_max.x, m_max.y, m_min.z));

    return corners;
}

void CBoundingBox::Render(const glm::mat4& modelMatrix, const glm::mat4& view, const glm::mat4& proj)
{
    GLuint program = CShaderManager::GetInstance()->UseShader(SHADER_TYPE::BOUNDING_BOX);

    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glUniformMatrix4fv(glGetUniformLocation(program, "viewTransform"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(program, "projectionTransform"), 1, GL_FALSE, glm::value_ptr(proj));
    glUniformMatrix4fv(glGetUniformLocation(program, "modelTransform"), 1, GL_FALSE, glm::value_ptr(modelMatrix));

    glLineWidth(4.0f);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    glDrawArrays(GL_LINE_LOOP, 4, 4);
    glDrawArrays(GL_LINE_LOOP, 8, 4);
    glDrawArrays(GL_LINE_LOOP, 16, 4);
    glDrawArrays(GL_LINE_LOOP, 20, 4);
    glDrawArrays(GL_LINE_LOOP, 24, 4);

    glDisableVertexAttribArray(0);

    m_matrix = modelMatrix;
}
