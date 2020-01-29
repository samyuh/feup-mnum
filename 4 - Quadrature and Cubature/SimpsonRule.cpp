#include <iostream>
#include <math.h>

using namespace std;

double f4(double x) { return sin(x) / pow(x, 2); }

double integrate_s(double a, double b, int n) {
    double s = f4(a);
    double h = (b - a) / n;
    for (int i = 1; i <= n; i++) {
        s += 2 * f4(a + i*h);
    }

    s = (h / 2) * s;
    cout << s << endl << endl;
    return s;
}

int main() {
    cout << integrate_s(pi / 2, pi, 16);
    return 0;
}