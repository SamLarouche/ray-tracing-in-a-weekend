#ifndef SCRT_MATERIAL_H
#define SCRT_MATERIAL_H

#include "ray.h"
#include "vec3.h"

namespace SCRT
{
	class Material
	{
	public:
		virtual bool scatter(const Ray& incomingRay, const HitRecord& hitData, Vec3<float>& attenuation, Ray& scatteredRay) const = 0;
	};
}



#endif // !SCRT_MATERIAL_H

