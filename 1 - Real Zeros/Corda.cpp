#include <iostream>
#include <math.h>

using namespace std;

double f(double x) { return -2.75 * (pow(x,3)) + 18 * pow(x,2) - 21 * x - 12; }

void corda(double a, double b)
{
	int steps = 0;
	double x, xn;

	do {
		x = (a * f(b) - b * f(a)) / (f(b) - f(a));
		if (f(a) * f(x) < 0)
			b = x;
		else
			a = x;
		xn = x;
		x = (a * f(b) - b * f(a)) / (f(b) - f(a));
		
		steps++;
	} while (abs(x - xn) >= pow(10, -5));

	cout << "X: " << x << endl;
	cout << steps <<endl << endl;

}

int main()
{
	//Zeros
	corda(-2, 0);
	corda(1, 3);
	corda(4, 7);
	return 0;
}