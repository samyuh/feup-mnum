#include <iostream>
#include <iomanip>

using namespace std;

//------------------------- Exercise 1
/* Encontrar o minino de uma função --> Minimizar uma função
*  Busca Unidimensional
*	Minimo -> 0
*	Intervalo - [-5,5]
*
*
*/

double zerof(double x) { return pow(x, 2) + pow(x, 4); }

const double B = (sqrt(5) - 1) / 2;
const double A = B * B;

void exercise1(double x1, double x2) {
	cout << "Rule of thirds" << endl;

	for (size_t i = 0; i < 40; i++) {
		double x3 = x1 + (x2 - x1) / 3;
		double x4 = x2 - (x2 - x1) / 3;
		if (zerof(x3) < zerof(x4))
			x2 = x4;
		else
			x1 = x3;

		cout << "x1: " << x1 << endl;
		cout << "x2: " << x2 << endl;
	}
	/*
	cout << "Golden Ratio" << endl;

	for (size_t i = 0; i < 40; i++) {
		double x3 = x1 + A * (x2 - x1);
		double x4 = x1 + B * (x2 - x1);
		if (zerof(x3) < zerof(x4))
			x2 = x4;
		else
			x1 = x3;

		cout << "x1: " << x1 << endl;
		cout << "x2: " << x2 << endl;
	}
	*/
}

//------------------------- Exercise 2

const double EULER = 2.7182;

double intf(double x) { return sqrt(1 + pow(2.5 * pow(EULER, 2.5 * x), 2)); }

void integration_t(double a, double b, double h) {
	int n = (b - a) / h;
	double sum = intf(a) + intf(b);
	for(int i = 1; i < n; i++) {
		sum += 2* intf(a + i*h);
	}
	sum = (h / 2.0) * (sum);
	cout << setprecision(6) << fixed << sum << endl << endl;
}

void integration_s(double a, double b, double h) {
	int n = (b - a) / h;
	double sum = intf(a) + intf(b);
	for (int i = 1; i < n; i++) {
		if (i % 2 == 0) 
			sum += 2 * intf(a + i * h);
		else 
			sum += 4 * intf(a + i * h);
	}
	sum = (h / 3.0) * (sum);
	cout << setprecision(6) << fixed <<sum << endl<<endl;
}

void exercise2() {
	integration_t(0, 1, 0.125);
	integration_s(0, 1, 0.125);
}


//------------------------- Exercise 3
// Intervalos das raizes -> [-6, -4] e [1,3]
double func(double x) { return pow(EULER, x) - x - 5; }
double funcdx(double x) { return pow(EULER, x) - 1; }

//Converge para o intervalo negativo
double rec1(double x) { return pow(EULER, x) - 5; }

//Converge para o intervalo positivo
double rec2(double x) { return log(5 + x); }

double rec2dx(double x) { return 1/(5 + x); }


void exercise3() {
	double x = 1;
	cout << "Picard Peano" << endl;
	for (size_t i = 0; i < 10; i++) {
		x = rec2(x);
		cout << x << endl;
	}
	x = 1;
	cout << "Newton" << endl;
	for (size_t i = 0; i < 10; i++) {
		x -= func(x) / funcdx(x);
		cout << x << endl;
	}
	//Newton converge mais rápido. Guess = 1. Paragem depois de 10 iterações Fórmulas = func(x) e funcdx(x)
}

//------------------------- Exercise 4

double dC(double C, double T) { return -pow(EULER, (-(0.5) / (T + 273)))*C; }
double dT(double C, double T) { return 30 * pow(EULER, (-(0.5) / (T + 273)))* C - 0.5*(T-20); }


void exercise4() {
	double t = 0, T = 25, C = 2.5, h = 0.25;
	//euler
	for (size_t i = 0; i < 3; i++) {
		cout << C << endl;
		cout << T << endl;
		double new_T = T + h * dT(C, T);
		double new_C =C + h * dC(C, T);
		t += h;
		C = new_C;
		T = new_T;
	}
	//RK4
	t = 0, T = 25, C = 2.5, h = 0.25;
	for (size_t i = 0; i < 3; i++) {
		cout << C << endl;
		cout << T << endl;
		double d1T = h*dT(C, T);
		double d1C = h*dC(C, T);

		double d2T = h*dT(C + d1C/2.0, T + d1T/2.0);
		double d2C = h*dC(C + d1C/2.0, T + d1T/2.0);

		double d3T = h*dT(C + d2C/2.0, T + d2T/2.0);
		double d3C = h*dC(C + d2C/2.0, T + d2T/2.0);

		double d4T = h*dT(C + d3C, T + d3T);
		double d4C = h*dC(C + d3C, T + d3T);

		T += (d1T / 6 + d2T / 3 + d3T / 3 + d4T / 6);
		C += (d1C / 6 + d2C / 3 + d3C / 3 + d4C / 6);
		t += h;
	}
}

//------------------------- Exercise 5

double w(double x, double y) { return -1.1 * x * y + 12 * y + 7 * x * x - 8 * x; }

double wx(double x, double y) { return -1.1*y + 14*x - 8; }
double wy(double x, double y) { return -1.1*x +12; }


void exercise5() {
	double x0 = 3, y0 = 1, lambda = 0.1, xn = x0, yn = y0;
	for (size_t i = 0; i < 10; i++) {
		x0 = xn;
		y0 = yn;
		cout << w(x0, y0) << endl;
		xn = x0 - lambda * wx(x0, y0);
		yn = y0 - lambda * wy(x0, y0);

		if (w(xn, yn) < w(x0, y0))
			lambda *= 2;
		else {
			lambda /= 2;
			xn = x0 - lambda * wx(x0, y0);
			yn = y0 - lambda * wy(x0, y0);
		}
	}


}

int main() {
	exercise5();


	return 0;
}