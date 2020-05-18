#ifndef SCRT_LAMBERT_H
#define SCRT_LAMBERT_H

#include "material.h"
#include "vec3.h"

namespace SCRT
{
	class Lambert : public Material
	{
	public:
		Lambert(const Vec3<float>& albedoVect) : _albedo(albedoVect) {}
		virtual bool scatter(const Ray& incomingRay, const HitRecord& hitData, Vec3<float>& attenuation, Ray& scatteredRay) const;
	private:
		Vec3<float> _albedo;
	};
}

#endif // !SCRT_LAMBERT_H