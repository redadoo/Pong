/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:41:46 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/19 00:37:03 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pong.h"

WindowInfo	windows;

int main(void)
{
	Ball		ball;
	Player		player;

	windows = InitWindowInfo(windows);
	player = InitiPlayer();
	ball = InitiBall(windows);

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow( windows.WindowSize.x,  windows.WindowSize.y, "Pong");

	SetTargetFPS(60);              

	while (!WindowShouldClose()) 
	{
		player = PlayerMovement(player,windows);
		
		ball.CurrentPos = BallResize(ball,windows);

		windows.WindowSize.y = GetScreenHeight();
		windows.WindowSize.x = GetScreenWidth();

		ball.CurrentPos = BallPhysics(ball.CurrentPos,ball.dir);

		BeginDrawing();
		
			DrawPlayer(player);
			ClearBackground(BLACK);
			DrawBackGround(windows);

			DrawCircleV(ball.CurrentPos, ball.radius, WHITE);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}