#include <iostream>
#include <fstream>
#include <vector>

#include "camera.h"
#include "mesh_object.h"
#include "ray.h"
#include "renderer.h"
#include "scene.h"
#include "sphere.h"
#include "vec3.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

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
	const int imgWindowWidth = 800;
	const int imgWindowHeight = 400;

	SCRT::Camera camera;
	SCRT::Scene scene;
	SCRT::Renderer renderer(imgWindowWidth, imgWindowHeight);

	SCRT::Sphere sphere1(SCRT::Vec3<float>(0.0, 0.0, -1.0), 0.5f);
	SCRT::Sphere sphere2(SCRT::Vec3<float>(0.0, -100.5, -1.0), 100.f);

	scene.addMesh(&sphere1);
	scene.addMesh(&sphere2);

	renderer.renderScene(scene);

	exportAsPNG(renderer.pixels, imgWindowWidth, imgWindowHeight);
}