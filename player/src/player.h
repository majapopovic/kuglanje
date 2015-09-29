#ifndef _PLAYER_H
#define _PLAYER_H
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>

#define LEFT_HAND -1
#define RIGHT_HAND 1

#define MIN_QUALITY 1
#define MAX_QUALITY 10

#define MAX_NAME_LENGTH 20


typedef struct player 
{
char name[20];
uint8_t quality;
int8_t hand;
} PLAYER;

PLAYER* playerCreate();

void setName(PLAYER*,char*);
void setQuality(PLAYER*,uint8_t);
void setHand(PLAYER*,int8_t);
#endif

