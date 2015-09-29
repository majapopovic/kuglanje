#include <string.h>
#include "player.h"


PLAYER* playerCreate()
{
	return (PLAYER*) malloc( sizeof(PLAYER) );
}


void setName(PLAYER* player,char* name)
{
if (strlen(name)==0)
strcpy(player->name, "Player");
else
{
if (strlen(name)<=MAX_NAME_LENGTH)
strcpy(player->name, name);
else
strncpy(player->name, name, MAX_NAME_LENGTH);
}
}


void setQuality(PLAYER* player,uint8_t quality)
{
if (quality>=MIN_QUALITY && quality<=MAX_QUALITY)
player->quality=quality;
else
player->quality=MIN_QUALITY;
}


void increaseQuality(PLAYER* player)
{
if (player->quality < MAX_QUALITY)
player->quality++;
else
player->quality=MAX_QUALITY;
}


void decreaseQuality(PLAYER* player)
{
if (player->quality > MIN_QUALITY)
player->quality--;
else
player->quality=MIN_QUALITY;
}




void setHand(PLAYER* player,int8_t hand)
{
if (hand==RIGHT_HAND || hand==LEFT_HAND)
player->hand=hand;
else
player->hand=RIGHT_HAND;
}
