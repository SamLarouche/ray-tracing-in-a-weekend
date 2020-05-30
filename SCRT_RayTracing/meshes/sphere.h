#ifndef SCRT_PRIM_SPHERE_H
#define SCRT_PRIM_SPHERE_H

#include "../materials/material.h"
#include "../math/vec3.h"

#include "mesh_object.h"


// TODO: separate the mesh from the object. The Object should have a pointer to its mesh just like it
// does with its material.

namespace SCRT
{
	class Sphere : public MeshObject
	{
	public:
		Sphere(Vec3<float> o, float r, Material* m) : _origin(o), _radius(r), _material_ptr(m) {};
		virtual bool hit(const Ray& r, HitRecord& data, float tMin = 0.0f, float tMax = FLT_MAX) const;
	private:
		Vec3<float> _origin;
		float _radius; 

		Material* _material_ptr;

	};
}

#endif // SCRT_PRIM_SPHERE_H