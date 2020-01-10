#include <iostream>
#include <math.h>

using namespace std;

//---------------------------------------------------------- Exercise 1
//TO DO

//---------------------------------------------------------- Exercise 2

double f1(double x, double y) { return  x*x-y-1.2; }
double f1lx(double x, double y) { return 2.0*x; }
double f1ly(double x, double y) { return -1; }
double f2(double x, double y) { return - x + y*y -1; }
double f2lx(double x, double y) { return -1; }
double f2ly(double x, double y) { return 2.0*y; }

void exercise2() {
	double guess_x = 1.0, guess_y = 1.0;
	for (size_t i = 0; i < 4; i++) {
		cout << guess_x << "   " << guess_y << endl;
		double x = guess_x - (f1(guess_x, guess_y)*f2ly(guess_x, guess_y) - f2(guess_x, guess_y) * f1ly(guess_x, guess_y))  / (f1lx(guess_x, guess_y) * f2ly(guess_x, guess_y) - f2lx(guess_x, guess_y)*f1ly(guess_x, guess_y));
		double y = guess_y -(f2(guess_x, guess_y) * f1lx(guess_x, guess_y) - f1(guess_x, guess_y) * f2lx(guess_x, guess_y)) / (f1lx(guess_x, guess_y) * f2ly(guess_x, guess_y) - f2lx(guess_x, guess_y) * f1ly(guess_x, guess_y));
		guess_x = x;
		guess_y = y;
	}
}

//---------------------------------------------------------- Exercise 3
//TO DO

//---------------------------------------------------------- Exercise 4

double f(double x) { return pow(x, 7) + 0.5 * x - 0.5; }

void exercise4(double a, double b) {
	double x;
	for (size_t i = 0; i < 4; i++) {
		cout << "a: " << a << endl;
		cout << "b: " << b << endl;
		x = (a * f(b) - b * f(a)) / (f(b) - f(a));
		cout << "X: " << x << endl;
		if (f(a) * f(x) < 0)
			b = x;
		else
			a = x;
	}
}

//---------------------------------------------------------- Exercise 5

double diffz(double t, double z) { return 0.5 + t * t + t * z; }
double diffy(double t, double z) { return z; }

void exercise5() {
	double h = 0.25, t = 0, y = 0, z = 1;
	double new_y, new_z;
	for (size_t i = 0; i < 3; i++) {
		cout << "t" << t << endl;
		cout << "y" << y << endl;
		new_y = y + h * diffy(t, z);
		new_z = z + h * diffz(t, z);
		t += h;
		z = new_z;
		y = new_y;
	}
	h = 0.25;
	t = 0;
	y = 0;
	z = 1;
	cout << "RK : \n";
	for (size_t i = 0; i < 3; i++) {
		cout << "t" << t << endl;
		cout << "y" << y << endl;
		double d1y = h * diffy(t, z);
		double d1z = h * diffz(t, z);

		double d2y = h * diffy(t + h/2.0, z + d1z/2.0);
		double d2z= h * diffz(t + h/ 2.0, z + d1z/2.0);

		double d3y = h * diffy(t + h/2.0, z + d2z/2.0);
		double d3z = h * diffz(t + h/2.0, z + d2z/ 2.0);

		double d4y = h * diffy(t + h, z + d3z);
		double d4z = h * diffz(t + h, z + d3z);

		z = z + (d1z / 6.0 + d2z / 3.0 + d3z / 3.0 + d4z / 6.0);
		y = y + (d1y / 6.0 + d2y / 3.0 + d3y / 3.0 + d4y / 6.0);
		t = t + h;
	}
}


//---------------------------------------------------------- Exercise 6

const double EULER = 2.7182;

double intf(double x) { return sqrt(1 + pow(1.5 * pow(EULER, 1.5 * x),2)); }

double integrate_t(double a, double b, int n){
	double s = intf(a) + intf(b);
	double h = (b - a) / n;
	for (int i = 1; i < n; i++) {
		s += 2 * intf(a + i * h);
	}
	s = (h / 2.0) * s;
	return s;
}

double integrate_s(double a, double b, int n) {
	double s = intf(a) + intf(b);
	double h = (b - a) / n;
	for (int i = 1; i < n; i++) {
		if(i % 2)
			s += 4* intf(a + i * h);
		else 
			s += 2* intf(a + i * h);
	}
	s = (h / 3.0) * s;
	return s;
}

void exercise6() {
	double h = 0.5;
	cout << integrate_t(0, 2, 4) << endl;
	cout << integrate_s(0, 2, 4) << endl;

	cout << integrate_t(0, 2, 8) << endl;
	cout << integrate_s(0, 2, 8) << endl;

	cout << integrate_t(0, 2, 16) << endl;
	cout << integrate_s(0, 2, 16) << endl;

	cout << "Erro: \n";
	cout << (integrate_t(0, 2, 16) - integrate_t(0, 2, 8)) /3 << endl;
	cout << (integrate_s(0, 2, 16) - integrate_s(0, 2, 8))/15 << endl;
}

int main() {
	return 0;
}

