#include <iostream>
#include <cmath>

using namespace std;

double w(double x, double y) { return -1.1 * x * y + 12 * y + 7 * x * x - 8 * x; }

double wx(double x, double y) { return -1.1*y + 14*x - 8; }
double wy(double x, double y) { return -1.1*x +12; }

void gradient(double x0, double y0, double lambda) {
    double  xn = x0, yn = y0;
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
	gradient(3, 1, 0.1);
	return 0;
}