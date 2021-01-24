#ifndef __DEFINITIONS_H_
#define __DEFINITIONS_H_

#define INT_MAX 2147483647

#define MEM_POS 0x1010
#define MEM_SHORT_SIZE MEM_SIZE_B / 8
#define MEM_SIZE_B 10240

#define GET_WAIT 1
#define GET_NOWAIT 2

#define _packed_ __attribute__((packed))

typedef unsigned long ulong_t;

#endif //inspired by aqua https://github.com/olekolek1000/Aqua