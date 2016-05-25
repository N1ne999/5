#include <root.h>
#include <math.h>

Roots proc(float a, float b, float c, int *stat)
{
	Roots reply;

	reply.discriminant = b * b - 4 * a * c;

	if (a == 0) {
		*stat = INVALID_INPUT;
		return reply;
	}
	else if (reply.discriminant < 0) {
		*stat = NO_ROOTS;
		return reply;
	}
	
	if (reply.discriminant == 0)
		*stat = ONE_ROOT;
	else 
		*stat = TWO_ROOTS;
	reply.x1 = (-b + sqrt(reply.discriminant)) / (2 * a);
	reply.x2 = (-b - sqrt(reply.discriminant)) / (2 * a);

	return reply;
}
