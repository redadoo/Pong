#include "../lib/pong.h"

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