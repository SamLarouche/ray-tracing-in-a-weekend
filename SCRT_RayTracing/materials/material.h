#ifndef SCRT_MATERIAL_H
#define SCRT_MATERIAL_H

#include "../ray.h"
#include "../math/vec3.h"

namespace SCRT
{
	class Material
	{
	public:
		virtual bool scatter(const Ray& incomingRay, const HitRecord& hitData, Vec3<float>& attenuation, Ray& scatteredRay) const = 0;
		virtual Vec3<float> reflect(const Vec3<float>& incomingVect, const Vec3<float>& surfaceNormal) const { return incomingVect - ((surfaceNormal * dot(incomingVect, surfaceNormal)) * 2.0f); }
	};
}



#endif // !SCRT_MATERIAL_H

