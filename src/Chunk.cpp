#include <Chunk.hpp>

void Chunk::GenMesh()
{
	for (int y = 0; y < layers.size(); y++)
        {
                for (int z = 0; z < CHUNK_SIZE; z++)
                {
                        for (int x = 0; x < CHUNK_SIZE; x++)
                        {
                                if (y < layers.size() - 1)
                                {
                                        if (layers[y + 1][x][z] != layers[y][x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[UP_FACE][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[UP_FACE][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[UP_FACE][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[UP_FACE][l]);
                                                }

                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[UP_FACE][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[UP_FACE][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[UP_FACE][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[UP_FACE][l]);
                                        }
                                
                                if (y > 0)
                                {
                                        if (layers[y - 1][x][z] != layers[y][x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[DOWN_FACE][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[DOWN_FACE][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[DOWN_FACE][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[DOWN_FACE][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[DOWN_FACE][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[DOWN_FACE][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[DOWN_FACE][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[DOWN_FACE][l]);
                                        }
                                if (z < CHUNK_SIZE - 1)
                                {
                                        if (layers[y][x][z + 1] != layers[y][x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[BACK_FACE][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[BACK_FACE][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[BACK_FACE][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[BACK_FACE][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[BACK_FACE][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[BACK_FACE][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[BACK_FACE][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[BACK_FACE][l]);
                                        }
                                if (z > 0)
                                {
                                        if (layers[y][x][z - 1] != layers[y][x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[FRONT_FACE][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[FRONT_FACE][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[FRONT_FACE][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[FRONT_FACE][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[FRONT_FACE][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[FRONT_FACE][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[FRONT_FACE][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[FRONT_FACE][l]);
                                        }
                                if (x < CHUNK_SIZE - 1)
                                {
                                        if (layers[y][x + 1][z] != layers[y][x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[LEFT_FACE][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[LEFT_FACE][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[LEFT_FACE][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[LEFT_FACE][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[LEFT_FACE][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[LEFT_FACE][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[LEFT_FACE][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[LEFT_FACE][l]);
                                        }
                                if (x > 0)
                                {
                                        if (layers[y][x - 1][z] != layers[y][x][z])
                                        {
                                                for (int l = 0; l < 30; l++)
                                                {
                                                        if ((l) % 5 == 0)
                                                                chunkFaces.push_back(faces[RIGHT_FACE][l] + x);
                                                        else if ((l - 1) % 5 == 0)
                                                                chunkFaces.push_back(faces[RIGHT_FACE][l] + y);
                                                        else if ((l - 2) % 5 == 0)
                                                                chunkFaces.push_back(faces[RIGHT_FACE][l] + z);
                                                        else
                                                                chunkFaces.push_back(faces[RIGHT_FACE][l]);
                                                }
                                        }
                                } else
                                        for (int l = 0; l < 30; l++)
                                        {
                                                if ((l) % 5 == 0)
                                                        chunkFaces.push_back(faces[RIGHT_FACE][l] + x);
                                                else if ((l - 1) % 5 == 0)
                                                        chunkFaces.push_back(faces[RIGHT_FACE][l] + y);
                                                else if ((l - 2) % 5 == 0)
                                                        chunkFaces.push_back(faces[RIGHT_FACE][l] + z);
                                                else
                                                        chunkFaces.push_back(faces[RIGHT_FACE][l]);
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
        posMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(xCoord * CHUNK_SIZE, 0, yCoord * CHUNK_SIZE));
}