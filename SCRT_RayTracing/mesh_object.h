#ifndef SCRT_MESH_OBJECT_H
#define SCRT_MESH_OBJECT_H

#include "material.h"
#include "ray.h"
#include "vec3.h"

namespace SCRT
{
	class MeshObject {
	public:
		virtual bool hit(const Ray& r, HitRecord& hitData, float tMin = 0.001, float tMax = FLT_MAX) const = 0;
	};
}



#endif // SCRT_MESH_OBJECT_H
