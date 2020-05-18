#include "scene.h"

void SCRT::Scene::addMesh(SCRT::MeshObject* mesh) {
	_mesh_ptrs.push_back(mesh);
}