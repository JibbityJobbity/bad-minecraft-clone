#ifndef BLOCK_H
#define BLOCK_H
#include <Chunk.hpp>
#include <glad/glad.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#define TEXTURE_PATH "textures/"

struct Block
{
	int ID = CHUNK_SIZE;
	unsigned int texture;
};

void LoadBlocks(std::vector<Block>* Blocks);
int FindBlock(int x, int y, int z, std::vector<Chunk>& map);

#endif
