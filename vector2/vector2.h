#ifndef VECTOR2_H
# define VECTOR2_H


typedef struct  vector2 {
    float x;                
    float y;                
}               vector2;

vector2		vector2_lerp(vector2 a, vector2 b, float t);
vector2		vector2_lerp_unclamped(vector2 a, vector2 b, float t);

#endif