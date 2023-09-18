#ifndef PONG_H
# define PONG_H

#include "raylib.h"


typedef struct  t_WindowInfo
{
	Vector2 WindowSize;
}               WindowInfo;

typedef struct  t_ball
{
	bool    IsMoving;
	Vector2 CurrentPos;
	Vector2 dir;
	float   Velocity;
	float   radius;
}               Ball;

typedef struct  t_player
{
	Vector2 dir;
	int     point;
	float   Velocity;
	Rectangle rec;
}               Player;

void 		DrawPlayer();
Player		InitiPlayer();
Ball		InitiBall(WindowInfo windows);
WindowInfo	InitWindowInfo(WindowInfo windows);
void		DrawBackGround(WindowInfo windows);
Vector2 	BallPhysics(Vector2 pos,Vector2 dir);
Player		PlayerMovement(Player player, WindowInfo window);
Vector2		BallResize(Ball ball, WindowInfo windows);
Vector2 PlayerResize(Player player, WindowInfo windows);

#endif