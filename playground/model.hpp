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
        std::vector<Texture> textures_loaded;
        std::vector<Mesh> meshes;
        std::string directory;
        /*  Functions   */
        void loadModel(std::string path);
        void processNode(aiNode *node, const aiScene *scene);
        Mesh processMesh(aiMesh *mesh, const aiScene *scene);
        std::vector<Texture> loadMaterialTextures(aiMaterial *mat, aiTextureType type, std::string typeName);
        unsigned int    TextureFromFile(const char *path, const std::string &directory, bool gamma = false);
};

#endif