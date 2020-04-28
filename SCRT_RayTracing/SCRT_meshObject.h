#ifndef SCRT_MESH_OBJECT_H
#define SCRT_MESH_OBJECT_H

#include "SCRT_ray.h"
#include "SCRT_vec3.h"

namespace SCRT
{
	struct meshRayHit {
		float       distance;   // distance from ray origin to hit
		vec3<float> coordinate; // coordinates of the hit in world space
		vec3<float> normal;     // normal of the mesh at hit point
	};

	class meshObject {
	public:
		virtual bool hit(const ray& r, meshRayHit& hitData, float tMin = 0.0f, float tMax = 999.0f) const = 0;
	};
}



#endif // SCRT_MESH_OBJECT_H
