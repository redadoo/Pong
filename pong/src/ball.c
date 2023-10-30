/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ball.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:14:12 by edoardo           #+#    #+#             */
/*   Updated: 2023/10/23 19:00:45 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pong.h"
#include <time.h>
#include <stdlib.h>

static int randomiNT(int min, int max){
   return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void	InitiBall(Ball *ball)
{
	ball->collider.radius = 10;
	ball->collider.pos.x = (float)(GetScreenWidth() / 2);
	ball->collider.pos.y = (float)(GetScreenHeight() / 2); 
	
	ball->IsMoving = false;
	ball->CurrentPos.x = (float)(GetScreenWidth() / 2); 
	ball->CurrentPos.y = (float)(GetScreenHeight() / 2);
}

vector2 BallPhysics(Ball *ball, vector2 dir)
{
	vector2 new_pos;

	new_pos.x = ball->CurrentPos.x + dir.x;
	new_pos.y = ball->CurrentPos.y + dir.y;

	ball->CurrentPos = vector2_lerp_unclamped(ball->CurrentPos,new_pos,30);
	ball->collider.pos = ball->CurrentPos;
}

void PushBall(Ball *ball)
{
	
}

vector2 RandoDir()
{
	int RandomX = randomiNT(0,1);
	vector2 RandDir;
	if (RandomX == 0)
	{
		RandDir.x = -1;
		RandDir.y = 0;
	}
	else
	{
		RandDir.x = 1;
		RandDir.y = 0;
	}
	return RandDir;
}
