#ifndef SCRT_METALLIC_H
#define SCRT_METALLIC_H

#include "material.h"
#include "../math/vec3.h"

namespace SCRT
{
	class Metallic : public Material
	{
	public:
		Metallic(const Vec3<float>& albedoVect) : _albedo(albedoVect) {}
		virtual bool scatter(const Ray& incomingRay, const HitRecord& hitData, Vec3<float>& attenuation, Ray& scatteredRay) const;
	private:
		Vec3<float> _albedo;
	};
}

#endif // !SCRT_METALLIC_H