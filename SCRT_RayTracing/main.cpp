#include <iostream>
#include <fstream>
#include <vector>

#include "SCRT_camera.h"
#include "SCRT_meshObject.h"
#include "SCRT_ray.h"
#include "SCRT_renderer.h"
#include "SCRT_scene.h"
#include "SCRT_sphere.h"
#include "SCRT_vec3.h"

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
	scene.addMesh(&sphere1);

	renderer.renderScene(scene);

	exportAsPNG(renderer.pixels, imgWindowWidth, imgWindowHeight);
}