#include <iostream>
#include <math.h>

using namespace std;

double f(double x) { return -2.75 * (pow(x,3)) + 18 * pow(x,2) - 21 * x - 12; }

void falsePosition(double a, double b) {
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

int main() {
    // In order to ensure that there is atleast one root in an interval [a, b] , f(a) * f(b) < 0
    falsePosition(-2, 0);
    falsePosition(1, 3);
    falsePosition(4, 7);
	return 0;
}