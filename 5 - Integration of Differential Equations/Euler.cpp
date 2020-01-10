#include <iostream>

using namespace std;

double dT(double T) { return -0.25 * (T - 37); }

void euler() {
    double t = 5, T = 3, h = 0.4;
    for (size_t i = 0; i < 4; i++) {
        cout << T << endl;
        cout << t << endl;
        T += h*dT(T);
        t += h;
    }
}

int main() {
    euler();
    return 0;
}