#pragma once
#include <vector>
#include <string>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Shader.h"
#include "Mesh.h"
#include "errors.h"
namespace GameEngine {
	class Model
	{
	public:
		/*  Functions   */
		Model(char *path);
		~Model();
		void draw(Shader shader);
	private:
		/*  Model Data  */
		std::vector<Mesh> meshes;
		std::string directory;
		/*  Functions   */
		void loadModel(std::string path);
		void processNode(aiNode *node, const aiScene *scene);
		Mesh processMesh(aiMesh *mesh, const aiScene *scene);
		std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type,
			std::string typeName);
	};
}