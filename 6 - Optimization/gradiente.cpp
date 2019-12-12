#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double f(double x, double y) { return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 12; }

double dfx(double x, double y) { return 4 * x - 2 * y; }
double dfy(double x, double y) { return 2 * y - 2 * x - 6; }

vector<double> gradiente(double x, double y)
{
	vector<double> gradiente;
	gradiente.push_back(dfx(x, y));
	gradiente.push_back(dfy(x, y));
	return gradiente;
}

vector<double> mgradiente(double h, double x, double y) {
	vector<double>Xn;
	Xn.push_back(1000); Xn.push_back(1000);
	vector<double> Xn1;
	Xn1.push_back(x); Xn1.push_back(y);
	int it = 0;

	while ((abs(Xn1[0] - Xn[0]) > 0.001) && (abs(Xn1[1] - Xn[1]) > 0.001))
	{
		it++;

		Xn[0] = Xn1[0];
		Xn[1] = Xn1[1];
		Xn1[0] = Xn[0] - h * gradiente(Xn[0], Xn[1])[0];
		Xn1[1] = Xn[1] - h * gradiente(Xn[0], Xn[1])[1];

		if (f(Xn1[0], Xn1[1]) < f(Xn[0], Xn[1]))
		{
			continue;
		}
		else if (f(Xn1[0], Xn1[1]) > f(Xn[0], Xn[1]))
		{
			h = h / 2;
			Xn1[0] = Xn[0] - h * gradiente(x, y)[0];
			Xn1[1] = Xn[0] - h * gradiente(x, y)[1];

		}

	}
	cout << "x: " << Xn1[0] << " | y: " << Xn1[1] << " | f(x,y): " << f(Xn1[0], Xn1[1]);
	cout << "\niteracoes: " << it;

	return Xn1;
}

int main()
{
	mgradiente(1, 1, 1);
	return 0;
}