#ifndef SCRT_MESH_OBJECT_H
#define SCRT_MESH_OBJECT_H

#include "../materials/material.h"
#include "../math/vec3.h"
#include "../ray.h"


namespace SCRT
{
	class MeshObject {
	public:
		virtual bool hit(const Ray& r, HitRecord& hitData, float tMin = 0.001, float tMax = FLT_MAX) const = 0;
	};
}



#endif // SCRT_MESH_OBJECT_H
