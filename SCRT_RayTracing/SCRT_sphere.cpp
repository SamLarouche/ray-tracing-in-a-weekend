#include "SCRT_sphere.h"

bool SCRT::Sphere::hit(const SCRT::Ray& currentRay, SCRT::meshRayHit& hitData, float tMin, float tMax) const
{
	SCRT::Vec3<float> centeredSpherePosition = currentRay.getOrigin() - _origin;

	float a = SCRT::dot(currentRay.getDirection(), currentRay.getDirection());
	float b = 2.0 * dot(centeredSpherePosition, currentRay.getDirection());
	float c = SCRT::dot(centeredSpherePosition, centeredSpherePosition) - _radius * _radius;

	float discriminant = b * b - 4 * a * c;

	if (discriminant > 0)
	{
		// we have to determine if one of the hit is in our acceptable margin
		float potentialHit = (((-1 * b) - sqrt(discriminant)) / (2.0f * a));
		if (potentialHit > tMin && potentialHit < tMax)
		{
			hitData.distance = (((-1 * b) - sqrt(discriminant)) / (2.0f * a));
			hitData.coordinate = currentRay.eval(hitData.distance);
			hitData.normal = (hitData.coordinate - _origin) / _radius;
			return true;
		}

		potentialHit = (((-1 * b) + sqrt(discriminant)) / (2.0f * a));
		if (potentialHit > tMin && potentialHit < tMax)
		{
			hitData.distance = (((-1 * b) - sqrt(discriminant)) / (2.0f * a));
			hitData.coordinate = currentRay.eval(hitData.distance);
			hitData.normal = (hitData.coordinate - _origin) / _radius;
			return true;
		}
	}

	return false;
}
