#ifndef SCRT_SCENE_H
#define SCRT_SCENE_H

#include <vector>

#include "camera.h"
#include "meshes/mesh_object.h"


namespace SCRT
{
	class Scene
	{
	public:
		Camera _camera;

		Scene() {}
		void addMesh(MeshObject* mesh);
		void removeMesh(MeshObject* mesh);

		int meshCount() const { return _mesh_ptrs.size(); }
		MeshObject* get(int meshIndex) const { return _mesh_ptrs[meshIndex]; }

	private:
		std::vector<MeshObject*> _mesh_ptrs;
	};
}

#endif // SCRT_SCENE_H