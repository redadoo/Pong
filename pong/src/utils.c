#include "../pong.h"

void DrawBackGround(WindowInfo windows)
{
	DrawLine(windows.WindowSize.x / 2,0,windows.WindowSize.x / 2,windows.WindowSize.y,WHITE);

}

Vector2 GetDir(Vector2 PrevPos,Vector2 PosNow)
{
	Vector2 diff;

	diff.x = PrevPos.x - PosNow.x;
	diff.y = PrevPos.y - PosNow.y;
	return(diff);
}

void ResizeSprite(Player *player, Ball *ball,WindowInfo *windows)
{
	if(IsWindowResized())
	{
		ball->CurrentPos.x = (float) GetScreenWidth() / 2; 
		ball->CurrentPos.y = (float) GetScreenHeight() / 2;
		ball->radius = 10;

		player->collider.size.y = 46;
		player->collider.size.x = 10;
		player->Velocity = 6;
		
	}
	else if (IsWindowMaximized())
	{
		ball->CurrentPos.x = (float) GetScreenWidth() / 2; 
		ball->CurrentPos.y = (float) GetScreenHeight() / 2;
		ball->radius = 20;

		player->collider.size.y = player->collider.size.y * (float)( GetScreenHeight() / windows->WindowSize.y);
		player->collider.size.x = player->collider.size.x * (float)( GetScreenWidth() / windows->WindowSize.x);
		player->Velocity = 10;
		
		windows->WindowSize.y = GetScreenHeight();
		windows->WindowSize.x = GetScreenWidth();
	}
}

void printV(vector2 v)
{
	printf("x : %.f ",v.x);
	printf("y : %.f \n",v.y);
}

bool collide_check(Ball *ball, Player *player)
{
	return check_collide_boxe_circle(player->collider, ball->collider);
}
