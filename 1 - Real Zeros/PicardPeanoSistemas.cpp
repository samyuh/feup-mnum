#include <iostream>
#include <math.h>

using namespace std;

const double e = pow(10, -5);

double f1(double x, double y) { return  sqrt((x*y +5*x -1) / 2.0); }
double f2(double x, double y) { return  sqrt(x+ 3* log(x)); }


void PicardPeanoSistema(double guess_x, double guess_y)
{
	double prev_x, prev_y, steps = 0;
	do
	{
		steps++;
		prev_x = guess_x;
		prev_y = guess_y;

		guess_x = f1(guess_x, guess_y);
		guess_y = f2(guess_x, guess_y);
	} while (abs(guess_x - prev_x) > e || abs(guess_y - prev_y) > e);

	cout << "X: " << guess_x << endl;
	cout << "Y: " << guess_y << endl;
	cout << "Steps: " << steps << endl << endl;

}

int main()
{
	//Zeros
	PicardPeanoSistema(4,4);
	return 0;
}