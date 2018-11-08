#ifndef MODEL_HPP
#define MODEL_HPP

#include "mesh.hpp"
#include "shader.hpp"

class Model {
    public:
        Model(char *path);
        void Draw(Shader shader);	
    private:
        /*  Model Data  */
        vector<Mesh> meshes;
        string directory;
        /*  Functions   */
        void loadModel(string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, string typeName);
};

#endif