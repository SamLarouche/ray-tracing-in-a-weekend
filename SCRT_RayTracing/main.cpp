#include <iostream>
#include <fstream>
#include <vector>

#include "math/vec3.h"
#include "materials/lambert.h"
#include "materials/metallic.h"
#include "meshes/sphere.h"

#include "camera.h"
#include "renderer.h"
#include "scene.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"

const std::string imgFilePath = "./render.ppm";

void exportAsPNG(SCRT::Vec3<int>* pixels, int width, int height)
{
	std::vector<unsigned char> pngData;
	for (int i = 0; i < width * height; ++i)
	{
		pngData.push_back(static_cast<unsigned char>(pixels[i].r()));
		pngData.push_back(static_cast<unsigned char>(pixels[i].g()));
		pngData.push_back(static_cast<unsigned char>(pixels[i].b()));
	}
	stbi_write_png("render.png", width, height, 3, pngData.data(), width*3);
}

int main() 
{
	// rendered image window properties
	const int imgWindowWidth = 200;
	const int imgWindowHeight = 100;

	SCRT::Camera camera;
	SCRT::Scene scene;
	SCRT::Renderer renderer(imgWindowWidth, imgWindowHeight);

	SCRT::Sphere sphere1(SCRT::Vec3<float>(0.0, 0.0, -1.0), 0.5f, new SCRT::Lambert(SCRT::Vec3<float>(0.8, 0.3, 0.3)));
	SCRT::Sphere sphere2(SCRT::Vec3<float>(0.0, -100.5, -1.0), 100.f, new SCRT::Lambert(SCRT::Vec3<float>(0.8, 0.8, 0.0)));
	SCRT::Sphere sphere3(SCRT::Vec3<float>(1.0, 0, -1.0), 0.5f, new SCRT::Metallic(SCRT::Vec3<float>(0.8, 0.6, 0.2)));
	SCRT::Sphere sphere4(SCRT::Vec3<float>(-1.0, 0, -1.0), 0.5f, new SCRT::Metallic(SCRT::Vec3<float>(0.8, 0.8, 0.8)));

	scene.addMesh(&sphere1);
	scene.addMesh(&sphere2);
	scene.addMesh(&sphere3);
	scene.addMesh(&sphere4);

	renderer.renderScene(scene);

	exportAsPNG(renderer.pixels, imgWindowWidth, imgWindowHeight);
}