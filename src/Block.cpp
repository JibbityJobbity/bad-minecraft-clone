#include <Block.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void LoadBlocks(std::vector<Block>* Blocks)
{
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

                Blocks->push_back(currentBlock);

                stbi_image_free(texData);
                i++;
                temp_str = std::to_string(i);
                std::string texturePath = "textures/" + temp_str + ".png";
                texData = stbi_load(texturePath.c_str(), &width, &height, &nChannels, 0);
        }
}