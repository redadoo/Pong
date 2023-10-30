
#include "../pong.h"

void InitEnemy(Player *player)
{
/* 	extern 		WindowInfo	windows
 */	
	player->pos.x = 780;
    player->pos.y = 160;
	player->collider.size.y = 60;
	player->collider.size.x = 11;
	player->collider.pos.x = 10;
	player->collider.pos.y = 50;
    player->collider.pos = player->pos; 
	player->Velocity = 6;
}