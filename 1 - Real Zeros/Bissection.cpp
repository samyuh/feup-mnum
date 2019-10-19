#include <iostream>
#include <math.h>

using namespace std;


double f(double x) { return x - 2 * log(x) - 5; }

void bissection(double a, double b)
{
	double xn;

	while (abs(a - b) >= pow(10, -5))
	{
		xn = (a + b) / 2.0;
		if (f(a) * f(xn) < 0)
			b = xn;
		else
			a = xn;
		cout << "A: " << a << " --- B: " << b << endl;
	}

}

int main()
{
	//First Zero
	bissection(0.01, 0.5);
	//Second Zero
	bissection(9, 10);

	return 0;
}