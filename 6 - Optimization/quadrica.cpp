#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


double dfdx(double x, double y) {return -sin(x) + x/2.0;}
double dfdy(double x, double y) {return cos(y)+y/2.0;}


int gradiente() {
    double x = 0, y = 0;
    double xn = 0, yn = 0;

    for(size_t i = 0; i < 4; i++){
        cout << x << endl;
        cout << y << endl;
        vector<vector<double>> matrix = {{1/(0.5-cos(x)),0}, {0,1/(0.5-sin(x))}};
        xn = x - (matrix[0][0] * dfdx(x,y) + matrix[0][1] * dfdy(x,y));
        yn = y - (matrix[1][0] * dfdx(x,y) + matrix[1][1] * dfdy(x,y));
        x = xn;
        y = yn;
    }

}

int main() {
    gradiente();
    return 0;
}