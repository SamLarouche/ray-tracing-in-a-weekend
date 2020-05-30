#ifndef SCRT_RAY_H
#define SCRT_RAY_H

#include "math/vec3.h"

namespace SCRT
{
	class Material;

	struct HitRecord {
		float        distance;     // distance from ray origin to hit
		Vec3<float>  coordinate;   // coordinates of the hit in world space
		Vec3<float>  normal;       // normal of the mesh at hit point
		Material*    material_ptr; // identifer of the material hit by the ray
	};

	class Ray 
	{
	public:
		Ray() {};
		Ray(const Vec3<float>& a, const Vec3<float>& b)
		{
			_origin = a;
			_direction = b;
		}

		Vec3<float> getOrigin() const { return _origin; }
		Vec3<float> getDirection() const { return _direction; }
		Vec3<float> eval(float x) const { return _origin + (x * _direction); }

	private:
		Vec3<float> _origin;
		Vec3<float> _direction;
	};
}

#endif // SCRT_RAY_H
