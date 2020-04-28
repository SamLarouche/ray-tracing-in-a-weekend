#include <iostream>
#include <fstream>
#include <vector>

#include "SCRT_meshObject.h"
#include "SCRT_ray.h"
#include "SCRT_sphere.h"
#include "SCRT_vec3.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

const std::string imgFilePath = "./render.ppm";

// Get the color of the pixel the r vector is aiming at
// TODO: make this a reusable function for different blends and colors
SCRT::vec3<float> linearBlendColor(const SCRT::ray& r) {
	SCRT::vec3<float> direction = r.getDirection();
	SCRT::vec3<float> startColor = SCRT::vec3<float>(1.0f, 1.0f, 1.0f);
	SCRT::vec3<float> endColor = SCRT::vec3<float>(0.5f, 0.7f, 1.0f);
	float t = 0.5f * (direction.y() + 1.0f);
	return (((1.0f - t) * startColor) + (t * endColor));
}

SCRT::vec3<float> computePixelFromRay(const SCRT::ray& r) {
	SCRT::meshRayHit rHit;
	SCRT::vec3<float> sphereCenter = SCRT::vec3<float>(0.0, 0.0, -1.0);
	SCRT::sphere testSphere = SCRT::sphere(sphereCenter, 0.5f);
	testSphere.hit(r, rHit); // value for t on ray R where the ray hits something
	if (rHit.distance > 0.0f)
	{
		SCRT::vec3<float> normal = (r.eval(rHit.distance) - sphereCenter).getUnitVec();
		return 0.5f * SCRT::vec3<float>(normal.x() + 1, normal.y() + 1, normal.z() + 1);
	}
	return linearBlendColor(r);
}

void exportAsPNG(const std::vector<SCRT::vec3<int>>& pixels, int width, int height)
{
	std::vector<unsigned char> pngData;
	for (const SCRT::vec3<int>& pixel : pixels)
	{
		pngData.push_back(static_cast<unsigned char>(pixel.r()));
		pngData.push_back(static_cast<unsigned char>(pixel.g()));
		pngData.push_back(static_cast<unsigned char>(pixel.b()));
	}
	stbi_write_png("render.png", width, height, 3, pngData.data(), width*3);
}

int main() 
{
	// rendered image window properties
	const int imgWindowWidth = 800;
	const int imgWindowHeight = 400;
	const SCRT::vec3<float> imgWindowCornerA = SCRT::vec3<float>(-2.0, -1.0, -1.0); // TODO: make coords relative to size
	const SCRT::vec3<float> imgWindowCornerB = SCRT::vec3<float>( 2.0, -1.0, -1.0);
	const SCRT::vec3<float> imgWindowCornerC = SCRT::vec3<float>( 2.0,  1.0, -1.0);
	const SCRT::vec3<float> imgWindowCornerD = SCRT::vec3<float>(-2.0,  1.0, -1.0);
	const SCRT::vec3<float> imgCameraPosition = SCRT::vec3<float>(0.0, 0.0, 0.0);

	const SCRT::vec3<float> widthVector = imgWindowCornerB - imgWindowCornerA;
	const SCRT::vec3<float> heightVector = imgWindowCornerD - imgWindowCornerA;

	std::vector<SCRT::vec3<int>> pixels; 

	for (int y = imgWindowHeight - 1; y > -1; --y) // pixels are written from top to bottom in ppm file
	{
		for (int x = 0; x < imgWindowWidth; ++x)
		{
			float u = float(x) / float(imgWindowWidth);
			float v = float(y) / float(imgWindowHeight);
			SCRT::vec3<float> rayDirection = imgWindowCornerA + (u * widthVector) + (v * heightVector);
			SCRT::ray currentRay = SCRT::ray(imgCameraPosition, rayDirection);

			SCRT::vec3<float> rayColor = computePixelFromRay(currentRay);
			int r = int(rayColor.r() * 255.99f);
			int g = int(rayColor.g() * 255.99f);
			int b = int(rayColor.b() * 255.99f);

			pixels.push_back(SCRT::vec3<int>(r, g, b));
		}
	}
	exportAsPNG(pixels, imgWindowWidth, imgWindowHeight);
}