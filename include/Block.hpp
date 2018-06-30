#ifndef BLOCK_H
#define BLOCK_H
#include <glad/glad.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#define TEXTURE_PATH "textures/"

struct Block
{
        int ID;
        unsigned int texture;
};

void LoadBlocks(std::vector<Block>* Blocks);

#endif
