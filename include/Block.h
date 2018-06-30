#ifndef BLOCK_H
#define BLOCK_H
#include <glad/glad.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

#define TEXTURE_PATH "textures/"

struct Block
{
        int ID;
        unsigned int texture;
};

void LoadBlocks();

static std::vector<Block> Blocks;

#endif