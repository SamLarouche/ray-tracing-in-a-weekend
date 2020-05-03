#ifndef SCRT_MESH_OBJECT_H
#define SCRT_MESH_OBJECT_H

#include "SCRT_ray.h"
#include "SCRT_vec3.h"

namespace SCRT
{
	struct meshRayHit {
		float       distance;   // distance from ray origin to hit
		Vec3<float> coordinate; // coordinates of the hit in world space
		Vec3<float> normal;     // normal of the mesh at hit point
	};

	class MeshObject {
	public:
		virtual bool hit(const Ray& r, meshRayHit& hitData, float tMin = 0.0f, float tMax = 999.0f) const = 0;
	};
}



#endif // SCRT_MESH_OBJECT_H
