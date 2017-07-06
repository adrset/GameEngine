#ifndef MESH_H
#define MESH_H

#include <gl/glew.h>

#include <assimp/Importer.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "Shader.h"
#include "Texture.h"
using namespace std;
namespace GameEngine {
	struct Vertex {
		glm::vec3 position;
		glm::vec3 normal;
		glm::vec2 texCoords;
		glm::vec3 tangent;
		glm::vec3 bitangent;
	};

	class Mesh {
	public:
		/*  Mesh Data  */
		vector<Vertex> vertices;
		vector<unsigned int> indices;
		vector<Texture> textures;
		unsigned int VAO;

		/*  Functions  */
		// constructor
		Mesh(vector<Vertex>& vertices, vector<unsigned int>& indices, vector<Texture>& textures);
		~Mesh();
		// render the mesh
		void draw(Shader shader) const;

	private:
		/*  Render data  */
		unsigned int VBO, EBO;

		/*  Functions    */
		// initializes all the buffer objects/arrays
		void setupMesh();
	};
}
#endif