#include "lambert.h"
#include "math_utils.h"

namespace SCRT
{
	bool Lambert::scatter(const Ray& incomingRay, const HitRecord& hit, Vec3<float>& attenuation, Ray& scatteredRay) const
	{
		scatteredRay = Ray(hit.coordinate, hit.coordinate + hit.normal + Random::randPointInUnitSphere());
		attenuation = _albedo;
		return true;
	}
}

