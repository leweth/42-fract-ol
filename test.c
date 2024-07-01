#include <stdio.h>

typedef struct s_struct
{
	double a;
	double b;
}	t_complex;

int main()
{
	t_complex a;

	a = (t_complex) {1, 2};
	printf("yo dude\n %lf\n %lf", a.a, a.b);
}