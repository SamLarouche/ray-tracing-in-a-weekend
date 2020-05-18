#ifndef SCRT_PRIM_SPHERE_H
#define SCRT_PRIM_SPHERE_H

#include "mesh_object.h"
#include "vec3.h"

namespace SCRT
{
	class Sphere : public MeshObject
	{
	public:
		Sphere(Vec3<float> o, float r) : _origin(o), _radius(r) {};
		virtual bool hit(const Ray& r, HitRecord& data, float tMin = 0.0f, float tMax = FLT_MAX) const;
	private:
		Vec3<float> _origin;
		float _radius; 
	};
}

#endif // SCRT_PRIM_SPHERE_H