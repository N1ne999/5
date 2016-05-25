#include <stdio.h>
#include <root.h>
#include <math.h>

int main() {

	float a;
	float b;
	float c;
	int stat;
	
	Roots reply;

	printf("Введите A, B, C для уравнения\n");
	scanf("%f %f %f", &a, &b, &c);

	reply = proc(a, b, c, &stat);
	if (stat > 0) {
		printf("Корни уравнения: %.2f & %.2f\n", reply.x1, reply.x2);
	}
	else
		printf("Корней нет\n");

	return 0;
}
