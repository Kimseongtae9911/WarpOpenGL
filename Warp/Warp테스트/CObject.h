#pragma once
#include "CMesh.h"
#include "CTransform.h"

class CObject
{
public:
	CObject();
	virtual ~CObject();

	virtual bool Update(float elapsedTime);
	virtual void Render();

	void SetDir(const Vector2& dir);

protected:
	CTransform* m_transform;
	Vector2 m_dir;	//πÊ«‚	
	float m_speed;

	shared_ptr<MeshInfo> m_mesh;
};

