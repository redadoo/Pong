#ifndef PONG_H
# define PONG_H

#include "../vector2/vector2.h"
#include "../collider/collider.h"
#include "raylib.h"
#include <stdio.h>


#define NORMAL_SPEED 7
#define CLONE_VEC(original) ((struct Vector2){.x = (original).x, .y = (original).y})


typedef struct  t_WindowInfo
{
	Vector2 WindowSize;
}               WindowInfo;

typedef struct  t_ball
{
	bool    IsMoving;
	vector2 CurrentPos;
	vector2 dir;
	float   Velocity;
	float   radius;
	circle_collider collider;
}               Ball;

typedef struct  t_player
{
	vector2			pos;
	box_collider	collider;
	int     		point;
	float   		Velocity;
}               Player;


extern WindowInfo	windows;

void		printV(vector2 v);
void 		DrawPlayer(Player player);
void		InitiPlayer(Player *player);
void		InitiBall(Ball *ball);
void		InitWindowInfo(WindowInfo *windows);
void		DrawBackGround(WindowInfo windows);
vector2 	BallPhysics(Ball *ball, vector2 dir);
void		PlayerMovement(Player *player, WindowInfo window);
void		ResizeSprite(Player *player, Ball *ball,WindowInfo *windows);
void		PushBall(Ball *ball);
vector2		RandoDir();
bool 		collide_check(Ball *ball, Player *player);
void 		InitEnemy(Player *player);
#endif