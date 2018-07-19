#ifndef CHUNK_H
#define CHUNK_H
#include <vector>
#include <array>
#include <iostream>
#include <Block.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define CHUNK_SIZE 16
#define UP_FACE 5
#define DOWN_FACE 4
#define LEFT_FACE 3
#define RIGHT_FACE 2
#define BACK_FACE 1
#define FRONT_FACE 0

class Chunk{
public:
        void GenMesh();
        std::vector<std::array<std::array<int, CHUNK_SIZE>, CHUNK_SIZE>> layers;
        int xCoord;
        int yCoord;
        unsigned int Mesh, VBO;
        glm::mat4 posMatrix;
        std::vector<float> chunkFaces;
        float faces[6][30] = {
                {
                0.0f, 0.0f, 0.0f,  1.0f, 0.0f,
                1.0f, 0.0f, 0.0f,  0.0f, 0.0f,
                1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
                1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
                0.0f,  1.0f, 0.0f,  1.0f, 1.0f,
                0.0f, 0.0f, 0.0f,  1.0f, 0.0f,
                },{
                1.0f, 0.0f,  1.0f,  1.0f, 0.0f,
                0.0f, 0.0f,  1.0f,  0.0f, 0.0f,
                1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
                0.0f,  1.0f,  1.0f,  0.0f, 1.0f,
                1.0f,  1.0f,  1.0f,  1.0f, 1.0f,
                0.0f, 0.0f,  1.0f,  0.0f, 0.0f,
                },{
                0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
                0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
                0.0f,  1.0f,  1.0f,  1.0f, 1.0f,
                0.0f, 0.0f,  1.0f,  1.0f, 0.0f,
                0.0f, 0.0f, 0.0f,  0.0f, 0.0f,
                0.0f,  1.0f,  1.0f,  1.0f, 1.0f,
                },{
                1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
                1.0f,  1.0f,  1.0f,  0.0f, 1.0f,
                1.0f,  1.0f, 0.0f,  1.0f, 1.0f,
                1.0f,  1.0f,  1.0f,  0.0f, 1.0f,
                1.0f, 0.0f, 0.0f,  1.0f, 0.0f,
                1.0f, 0.0f,  1.0f,  0.0f, 0.0f,
                },{
                0.0f, 0.0f, 0.0f,  1.0f, 1.0f,
                1.0f, 0.0f,  1.0f,  0.0f, 0.0f,
                1.0f, 0.0f, 0.0f,  0.0f, 1.0f,
                1.0f, 0.0f,  1.0f,  0.0f, 0.0f,
                0.0f, 0.0f, 0.0f,  1.0f, 1.0f,
                0.0f, 0.0f,  1.0f,  1.0f, 0.0f,
                },{
                1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
                0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
                1.0f,  1.0f, 0.0f,  1.0f, 1.0f,
                0.0f,  1.0f, 0.0f,  0.0f, 1.0f,
                1.0f,  1.0f,  1.0f,  1.0f, 0.0f,
                0.0f,  1.0f,  1.0f,  0.0f, 0.0f
                }
        };
};

#endif