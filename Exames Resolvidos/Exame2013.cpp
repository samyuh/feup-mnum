#include <iostream>
#include <iomanip>

using namespace std;

//---------Exercise 1

double dz(double t, double z) { return 0.5 + t * t + t * z; }
double dy(double t, double z) { return z; }

void ex1() {
	//EUler
	double t = 0, h = 0.25, y = 0, z = 1;
	for (size_t i = 0; i < 3; i++) {
		cout << t << endl;
		cout << y << endl;
		double yn = y + h * dy(t, z);
		double zn = z + h * dz(t, z);
		y = yn;
		z = zn;
		t += h;
	}
	//RK4
	t = 0, h = 0.25, y = 0, z = 1;
	for (size_t i = 0; i < 3; i++) {
		cout << t << endl;
		cout << y << endl;
		double d1y = h * dy(t, z);
		double d1z = h * dz(t, z);

		double d2y = h * dy(t +h/2, z + d1z / 2);
		double d2z = h * dz(t +h/2, z + d1z / 2);

		double d3y = h * dy(t + h/2, z + d2z / 2);
		double d3z = h * dz(t + h/2, z + d2z/2);

		double d4y = h * dy(t + h, z + d3z);
		double d4z = h * dz(t + h, z + d3z);
		y += (d1y/6 + d2y/3 + d3y/3 + d4y/6);
		z += (d1z / 6 + d2z / 3 + d3z / 3 + d4z/6);
		t += h;
	}
}

//------------- Exercise 2

//------------- Exercise 3

double f(double x, double y) { return 3 * x * x - x * y + 11 * y + y*y - 8 * x; }
double fx(double x, double y) { return 6 * x - y - 8; }
double fy(double x, double y) { return -x + 11 + 2 * y; }

void ex3() {
	double lambda = 0.5, x = 2, xn = x, y=2, yn=y;
	for (size_t i = 0; i < 10; i++) {
		cout << x << " " << f(x,y) << " " << fx(x,y) << endl;
		cout << y << " " << f(x,y) << " " << fy(x,y) << endl;
		xn = x - lambda * fx(x, y);
		yn = y - lambda * fy(x, y);
		if (f(xn, yn) < f(x, y)) {
			lambda *= 2;
			x = xn;
			y = yn;
		}
		else
			lambda /= 2;
	}
}

//-------------Exercise 4

double integrate(double x) { return pow(2.718, 1.5 * x); }

double s(double a, double b, double h) {
	int n = (b - a) / h;
	double sum = integrate(a) + integrate(b);
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0)
			sum += 2 * integrate(a + i * h);
		else
			sum += 4 * integrate(a + i * h);
	}
	return sum * h / 3.0;
}


void ex4() {
	cout << fixed << setprecision(5) <<s(1, 1.5, 0.125) << endl;
	cout << fixed << setprecision(5) << s(1, 1.5, 0.125/2) << endl;
	cout << fixed << setprecision(5) << s(1, 1.5, 0.125/4) << endl;
	double s1 = s(1, 1.5, 0.125), s2= s(1, 1.5, 0.125/2), s3 = s(1, 1.5, 0.125/4);
	cout << (s2 - s1) / (s3 - s2) << endl;
	cout << (s3 - s2) / 16.0 << endl;
}

//---------------- Exercise 5

double n(double x) { return (x - 3.7) + pow(cos(x + 1.2), 3); }
double dn(double x) { return 1 - 3 * pow(cos(x + 1.2),2)*sin(x + 1.2); }

void ex5() {
	double x = 3.8;
	for (int i = 0; i < 3; i++) {
		cout << x << endl;
		x -= n(x) / dn(x);
	}
}

int main() {

	ex5();
	return 0;
}