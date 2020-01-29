#include <iostream>
#include <math.h>

const double B = (sqrt(5) - 1)/2;
const double A = B * B;

double f(double x) { return pow((2*x+1),2) - 5 * cos(10*x); }

double quadratic_interpolation(double x1, double x2, double x3){
    return x2 + ((x2-x1) * (sin(x1) - sin(x3))) / (2*(sin(x3)-2*sin(x2)+sin(x1)));
}

double method_of_thirds(double x0, double x1) {
    while(abs(x1 - x0) > 0.000000001) {
        double x2 = x0 + ((x1 - x0) / 3);
        double x3 = x1 - ((x1 - x0) / 3);

        if(sin(x2) > sin(x3))
            x0 = x2;
        else
            x1 = x3;
    }
    return x0;
}

double golden_ratio(double x1, double x2) {
    while(abs(x2 - x1) >= 0.001) {
        double x3 = x1 + A * (x2 - x1);
        double x4 = x1 + B * (x2 - x1);
        if(f(x3) < f(x4))
            x2 = x4;
        else
            x1 = x3;
    }

    return x1;
}

double unidimensional_search(double guess){
    double step = 0.1;
    if(f(guess) < f(guess+step))
        step = -step;
    double x0 = step;
    double x1 = guess;
    double x2 = guess + 2*step;
    while(f(x1) > f(x2)) {
        x0 = x1;
        x1 = x2;
        x2 = x2 + step;
        std::cout << "Interval: " << x0 << " " << x1 << " " << x2 << " " << std::endl;
    }

    return golden_proportion(x0,x2);
}

int main() {
    std::cout << "Final Value: " <<  golden_proportion(-1,0);
    return 0;
}