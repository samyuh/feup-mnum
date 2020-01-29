#include <iostream>
#include <math.h>

using namespace std;

double f4(double x) { return sin(x) / pow(x, 2); }

double integrate_t(double a, double b, int n){
    double s = f4(a);
    double h = (b - a) / n;
    for (int i = 1; i <= n; i++) {
        if(i % 2== 0)
            s += 2 * f4(a + i * h);
        else
            s += 4 * f4(a + i * h);
    }

    s = (h / 3) * s;
    return s;
}

int main() {
    cout << integrate_t(pi / 2, pi, 16);
    return 0;
}