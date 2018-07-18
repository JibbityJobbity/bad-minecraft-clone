#ifndef CHUNK_H
#define CHUNK_H
#include <vector>
#include <array>
#include <iostream>
#include <Block.hpp>

class Chunk{
public:
        void GenMesh();
        std::vector<std::array<std::array<int, 16>, 16>> layers;
        int xCoord;
        int yCoord;
        unsigned int Mesh, VBO;
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