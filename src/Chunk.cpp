#include <Chunk.hpp>

#include <Block.hpp>

void Chunk::GenMesh(std::vector<Chunk>& map)
{
	int x = map.size();
	for (int y = 0; y < layers.size(); y++) // For each layer
	{
		for (int z = 0; z < CHUNK_SIZE; z++) // For each z of the layer
		{
			for (int x = 0; x < CHUNK_SIZE; x++) // For each x of the layer
			{
				if (layers[y][x][z] != 0)	// If it's an air block, skip determining its faces
				{
					if (y < layers.size() - 1) // If it's not the top layer
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
					} else if (layers[y][x][z] != 0)	// It's the top layer, 
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
						//int below = layers[y - 1][x][z];
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
					} else if (layers[y][x][z] != 0)
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
					if (FindBlock(x + (CHUNK_SIZE * xCoord), y, z + (CHUNK_SIZE * zCoord) + 1, map) != layers[y][x][z])
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
					if (FindBlock(x + (CHUNK_SIZE * xCoord), y, z + (CHUNK_SIZE * zCoord) - 1, map) != layers[y][x][z])
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
					if (FindBlock(x + (CHUNK_SIZE * xCoord) + 1, y, z + (CHUNK_SIZE * zCoord), map) != layers[y][x][z])
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
					if (FindBlock(x + (CHUNK_SIZE * xCoord) - 1, y, z + (CHUNK_SIZE * zCoord), map) != layers[y][x][z])
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
				}
			}
		}
	}
	glGenBuffers(1, &VBO);
	glGenVertexArrays(1, &Mesh);
	
	glBindVertexArray(Mesh);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(int) * chunkFaces.size(), chunkFaces.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_INT, GL_FALSE, 5 * sizeof(int), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_INT, GL_FALSE, 5 * sizeof(int), (void*)(3 * sizeof(int)));
	glEnableVertexAttribArray(1);
	posMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(xCoord * CHUNK_SIZE, 0, zCoord * CHUNK_SIZE));
}