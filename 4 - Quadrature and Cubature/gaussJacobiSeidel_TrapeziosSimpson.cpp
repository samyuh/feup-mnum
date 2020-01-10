#include <iostream>
#include <math.h>
using namespace std;

double f1(double x1, double x2, double x3) { return (7 - x2 - x3) / 3; }
double f2(double x1, double x2, double x3) { return (4 - x1 - 2*x3) / 4; }
double f3(double x1, double x2, double x3) { return (5 - 2*x2) / 5; }
double f4(double x) { return sin(x) / pow(x, 2); }

const double pi = 3.14159;

void guass_jacobi(double x1, double x2, double x3) {

	for (int i = 0; i < 10; i++)
	{
		
		double x1n = f1(x1, x2, x3);
		double x2n = f2(x1, x2, x3);
		double x3n = f3(x1, x2, x3);
		x1 = x1n;
		x2 = x2n;
		x3 = x3n;
		cout << x1 << " " << x2 << " " << x3 << " " << endl;
	}
}

void guass_seidel(double x1, double x2, double x3) {

	for (int i = 0; i < 10; i++)
	{

		x1 = f1(x1, x2, x3);
		x2 = f2(x1, x2, x3);
		x3 = f3(x1, x2, x3);

		cout << x1 << " " << x2 << " " << x3 << " " << endl;
	}
}

double integrate_s(double a, double b, int n)
{

	double s = f4(a);
	double h = (b - a) / n;
	for (int i = 1; i <= n; i++)
	{
		s += 2 * f4(a + i*h);
	}

	s = (h / 2) * s;
	cout << s << endl << endl;
	return s;
}

double integrate_t(double a, double b, int n)
{
	double s = f4(a);
	double h = (b - a) / n;
	for (int i = 1; i <= n; i++)
	{
		if(i % 2== 0)
			s += 2 * f4(a + i * h);
		else
			s += 4 * f4(a + i * h);
	}

	s = (h / 3) * s;
	return s;
}

int main() {

	cout << (integrate_s(pi / 2, pi, 16) - integrate_s(pi/2, pi, 8) )/ 3 << endl;
	cout << (integrate_t(pi / 2, pi, 16) - integrate_t(pi / 2, pi, 8)) / 15 << endl;

	
	return 0;
}