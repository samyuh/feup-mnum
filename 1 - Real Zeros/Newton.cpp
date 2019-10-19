#include <iostream>
#include <math.h>

using namespace std;

double f(double x) { return  2 * pow(x,2) - 5 * x - 2; }
double df(double x) { return  4 * x - 5; }

double iteratorNewton(double x) { return f(x) / df(x); }

void Newton(double guess, int steps)
{
	for (int i = 0; i < steps; i++)
	{
		guess -= iteratorNewton(guess);
	}


	cout << "X: " << guess << endl;
	cout << "Steps: " << steps << endl << endl;

}

int main()
{
	//Zeros
	Newton(0, 20);
	return 0;
}