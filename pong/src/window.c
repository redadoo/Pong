/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edoardo <edoardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 00:15:07 by edoardo           #+#    #+#             */
/*   Updated: 2023/09/19 00:24:54 by edoardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/pong.h"

WindowInfo InitWindowInfo(WindowInfo windows)
{
	windows.WindowSize.x = 800;
	windows.WindowSize.y = 450;
	return windows;
}

