#ifndef COLLIDER_H
# define COLLIDER_H

#include "../vector2/vector2.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


typedef struct	box_collider
{
	vector2		pos;
	vector2		size;
}				box_collider;

typedef struct	circle_collider
{
	vector2		pos;
	float		radius;
}				circle_collider;

typedef struct	custom_polygon_collider
{
	//soon..
}				custom_polygon_collider;


bool check_collide_boxes(box_collider a, box_collider b);
bool check_collide_boxe_circle(box_collider a, circle_collider b);

#endif