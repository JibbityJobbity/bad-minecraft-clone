#include <Block.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void LoadBlocks(std::vector<Block>* blocks)
{
	stbi_set_flip_vertically_on_load(true);
	int i = 0, width, height, nChannels;
	std::string temp_str = std::to_string(i);
	std::string texturePath = "textures/" + temp_str + ".png";
	unsigned char* texData = stbi_load(texturePath.c_str(), &width, &height, &nChannels, 0);
	while (texData)
	{
		Block currentBlock;
		currentBlock.ID = i;

		glGenTextures(1, &currentBlock.texture);
		glBindTexture(GL_TEXTURE_2D, currentBlock.texture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, texData);
		glGenerateMipmap(GL_TEXTURE_2D);

		blocks->push_back(currentBlock);

		stbi_image_free(texData);
		i++;
		temp_str = std::to_string(i);
		std::string texturePath = "textures/" + temp_str + ".png";
		texData = stbi_load(texturePath.c_str(), &width, &height, &nChannels, 0);
	}
}

int FindBlock(int x, int y, int z, std::vector<Chunk>& map)
{
	int blockX = x % CHUNK_SIZE;
	int blockZ = z % CHUNK_SIZE;
	if (blockX == 1 && y == 0 && blockZ == 1)
	{
		std::cout << "yeet ";
	}
	else if (blockX == 1 && y == 1 && blockZ == 1){ 
		std::cout << "yeeter ";
	}
	for (int i = 0; i < map.size(); i++)
	{
		if (map.at(i).xCoord == x / CHUNK_SIZE && map.at(i).zCoord == z / CHUNK_SIZE)
		{
			int returnID = map.at(i).layers[y][blockX][blockZ];
			return returnID;
		}
	}

	return -1;
}