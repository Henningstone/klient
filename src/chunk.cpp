#include "chunk.h"

char chunk_get(Chunk *chunk, int x, int y, int z) {
  int lx = x - chunk->p * CHUNK_SIZE;
  int ly = y - chunk->k * CHUNK_SIZE;
  int lz = z - chunk->q * CHUNK_SIZE;

  // TODO: Looking for a block in the wrong chunk is a bit weird, but hit code does it
  if(lx < CHUNK_SIZE && ly < CHUNK_SIZE && lz < CHUNK_SIZE &&
     lx >= 0 && ly >= 0 && lz >= 0) {
    return chunk->blocks[lx+ly*CHUNK_SIZE+lz*CHUNK_SIZE*CHUNK_SIZE];
  } else {
    return 0;
  }
}

void chunk_set(Chunk *chunk, int x, int y, int z, int w) {
  int lx = x - chunk->p * CHUNK_SIZE;
  int ly = y - chunk->k * CHUNK_SIZE;
  int lz = z - chunk->q * CHUNK_SIZE;

  if(lx < CHUNK_SIZE && ly < CHUNK_SIZE && lz < CHUNK_SIZE &&
     lx >= 0 && ly >= 0 && lz >= 0) {
    chunk->blocks[lx+ly*CHUNK_SIZE+lz*CHUNK_SIZE*CHUNK_SIZE] = w;
  }
}
