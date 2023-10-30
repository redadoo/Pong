/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:13:48 by edoardo           #+#    #+#             */
/*   Updated: 2023/10/23 19:00:22 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pong.h"

void	InitiPlayer(Player *player)
{
	box_collider   coll;

	coll.size.y = 60;
	coll.size.x = 11;
	coll.pos.x = 10;
	coll.pos.y = 160;
	player->collider = coll;
	player->pos = coll.pos;
	player->Velocity = 6;
}

void	DrawPlayer(Player player)
{
	DrawRectangleV(CLONE_VEC(player.pos),CLONE_VEC(player.collider.size),WHITE);
}

void	PlayerMovement(Player *player, WindowInfo window)
{
	if ((IsKeyDown(KEY_W)) && player->pos.y > 10) player->pos.y -= player->Velocity;
	if ((IsKeyDown(KEY_S)) && player->pos.y < window.WindowSize.y - 60) player->pos.y += player->Velocity;
	player->collider.pos = player->pos;
}
