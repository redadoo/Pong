/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:41:46 by edoardo           #+#    #+#             */
/*   Updated: 2023/10/23 18:37:54 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pong.h"

WindowInfo	windows;

int main(void)
{
	
	Ball		ball;
	Player		player;
	Player		enemy;
	
	InitWindowInfo(&windows);

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow( windows.WindowSize.x,  windows.WindowSize.y, "Pong");

	SetTargetFPS(60);              

	InitEnemy(&enemy);
	InitiPlayer(&player);
	InitiBall(&ball);

	ball.dir = RandoDir();
	
	while (!WindowShouldClose()) 
	{
 		ResizeSprite(&player,&ball,&windows);
 		

		PlayerMovement(&player,windows);

		if(collide_check(&ball,&player) || collide_check(&ball,&enemy))
		{
			ball.dir.x = -ball.dir.x;

			BallPhysics(&ball,ball.dir);
		}
		else
			BallPhysics(&ball,ball.dir);

		
		BeginDrawing();
		
			ClearBackground(BLACK);
			DrawBackGround(windows);
			DrawPlayer(player);
			DrawCircleV(CLONE_VEC(ball.CurrentPos), ball.collider.radius, WHITE);
			DrawPlayer(enemy);

		EndDrawing();
	}
	CloseWindow();
	return 0;
}
