/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:13:48 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/19 00:28:28 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pong.h"

Vector2 PlayerResize(Player player, WindowInfo windows)
{
/* 	if(IsWindowMaximized() || IsWindowResized() || IsWindowState(FLAG_WINDOW_MINIMIZED) && !ball.IsMoving)
	{
		player.rec.x = (float) windows.WindowSize.x / 2; 
		player.rec.y = (float) windows.WindowSize.y / 2;
	} */
}

Player InitiPlayer()
{
	Player		player;
	Rectangle   rec;

	rec.height = 46;
	rec.width = 13;
	rec.x = 10;
	rec.y = 50;
	player.rec = rec;
	player.Velocity = 4;
	return player;
}

void DrawPlayer(Player player)
{
	DrawRectangleRec(player.rec,WHITE);
}

Player PlayerMovement(Player player, WindowInfo window)
{
	if ((IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) && player.rec.y > 10) player.rec.y -= player.Velocity;
	if ((IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) && player.rec.y < window.WindowSize.y - 60) player.rec.y += player.Velocity;
	return player;
}
