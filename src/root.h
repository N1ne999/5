#ifndef ROOT_H
#define ROOT_H

#define TWO_ROOTS 2
#define ONE_ROOT 1
#define NO_ROOTS 0
#define INVALID_INPUT -1

typedef struct {
	float x1;
	float x2;
	float discriminant;
} Roots;

Roots proc(float a, float b, float c, int *stat);

#endif
