#include <Chunk.hpp>

void Chunk::GenMesh()
{
	for (int y = 0; y < layers.size(); y++)
        {
                std::array<std::array<int, 16>, 16> layer = layers.at(y);
                for (int z = 0; z < layer.size(); z++)
                {
                        for (int x = 0; x < layer[z].size(); x++)
                        {
                                if (y < layers.size() - 1)
                                {
                                        if (layers[y + 1][x][z] != layer[x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[5][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[5][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[5][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[5][l]);
                                                        
                                                }

                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[5][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[5][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[5][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[5][l]);
                                        }
                                
                                if (y > 0)
                                {
                                        if (layers[y - 1][x][z] != layer[x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[4][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[4][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[4][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[4][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[4][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[4][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[4][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[4][l]);
                                        }                    
                                if (z < layer.size() - 1)
                                {
                                        if (layer[x][z + 1] != layer[x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[1][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[1][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[1][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[1][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[1][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[1][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[1][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[1][l]);
                                        }
                                if (z > 0)
                                {
                                        if (layer[x][z - 1] != layer[x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[0][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[0][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[0][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[0][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[0][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[0][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[0][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[0][l]);
                                        }
                                if (x < layer.size() - 1)
                                {
                                        if (layer[x + 1][z] != layer[x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[3][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[3][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[3][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[3][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[3][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[3][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[3][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[3][l]);
                                        }
                                if (x > 0)
                                {
                                        if (layer[x - 1][z] != layer[x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[2][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[2][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[2][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[2][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[2][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[2][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[2][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[2][l]);
                                        }
                        }
                }
        }
        glGenBuffers(1, &VBO);
        glGenVertexArrays(1, &Mesh);
        
	glBindVertexArray(Mesh);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, chunkFaces.size(), chunkFaces.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}