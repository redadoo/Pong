#include "collider.h"

static int min(int a, int b)
{
    if(b < a)
        return b;
    return a;
}

static int max(int a, int b)
{
    if(b > a)
        return b;
    return a;
}

bool check_collide_boxes(box_collider a, box_collider b)
{
    if (a.pos.x + a.size.x > b.pos.x && a.pos.x < b.pos.x + b.size.x)
        return true;
    if (a.pos.y + a.size.y > b.pos.y && a.pos.y < b.pos.y + b.size.y)
        return true;
    return false;
}

bool check_collide_boxe_circle(box_collider a, circle_collider b)
{
    float deltaX = abs(b.pos.x - max(a.pos.x, min(b.pos.x, a.pos.x + a.size.x)));
    float deltaY = abs(b.pos.y - max(a.pos.y, min(b.pos.y, a.pos.y + a.size.y)));
    
    if (deltaX * deltaX + deltaY * deltaY <= b.radius * b.radius)
        return true;
    return false;
}