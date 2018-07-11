#ifndef CHUNK_H
#define CHUNK_H
#include <vector>
#include <Block.hpp>

struct Chunk{
        std::vector<std::array<std::array<int, 8>, 8>> layers;
        int xCoord;
        int yCoord;
};

#endif