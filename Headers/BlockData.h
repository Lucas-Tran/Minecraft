#ifndef BLOCK_DATA_H
#define BLOCK_DATA_H

struct Block {
    bool solid;
};

#define SOLID 0
#define AIR 1

extern Block blockData[];

#endif