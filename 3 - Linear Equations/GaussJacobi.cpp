#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

double f1(double x1, double x2, double x3) { return (7 - x2 - x3) / 3; }
double f2(double x1, double x2, double x3) { return (4 - x1 - 2*x3) / 4; }
double f3(double x1, double x2, double x3) { return (5 - 2*x2) / 5; }
double f4(double x) { return sin(x) / pow(x, 2); }

const double pi = 3.14159;

void gaussJacobi(double x1, double x2, double x3) {
    for (int i = 0; i < 10; i++) {
        double x1n = f1(x1, x2, x3);
        double x2n = f2(x1, x2, x3);
        double x3n = f3(x1, x2, x3);
        x1 = x1n;
        x2 = x2n;
        x3 = x3n;
        cout << x1 << " " << x2 << " " << x3 << " " << endl;
    }
}


int main() {

    return 0;
}