#ifndef CHUNK_H
#define CHUNK_H
#include <vector>
#include <Block.hpp>

class Chunk{
public:
        void GenMesh();
        std::vector<std::array<std::array<int, 16>, 16>> layers;
        int xCoord;
        int yCoord;
        unsigned int Mesh;
};

#endif