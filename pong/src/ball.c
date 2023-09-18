/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:14:12 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/19 00:35:56 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pong.h"

Vector2 BallResize(Ball ball, WindowInfo windows)
{
	if(IsWindowMaximized() || IsWindowResized() || IsWindowState(FLAG_WINDOW_MINIMIZED) && !ball.IsMoving)
	{
		ball.CurrentPos.x = (float) windows.WindowSize.x / 2; 
		ball.CurrentPos.y = (float) windows.WindowSize.y / 2;
	}

	return ball.CurrentPos;
}

Ball InitiBall(WindowInfo windows)
{
	Ball ball;
	ball.radius = 10;
	ball.IsMoving = false;
	ball.CurrentPos.x = (float) windows.WindowSize.x / 2; 
	ball.CurrentPos.y = (float) windows.WindowSize.y / 2;
	return ball;
}

Vector2 BallPhysics(Vector2 pos,Vector2 dir)
{
	
}