#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void showMatrix(vector<vector<double>> matrix) {
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 4; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

void gauss(vector<vector<double>> matrix) {
	double pivot;

	pivot = matrix[0][0];
	for (size_t i = 0; i < matrix[0].size(); i++)
		matrix[0][i] = matrix[0][i] / pivot;

	for(size_t row = 1; row < matrix.size(); row++){
		pivot = -matrix[row][0];
		for (size_t i = 0; i < matrix[0].size(); i++)
			matrix[row][i] = matrix[0][i] * pivot + matrix[row][i];
	}

	pivot = -matrix[1][1];
	for (size_t i = 1; i < matrix[0].size(); i++)
		matrix[2][i] = matrix[1][i] * pivot + matrix[2][i];

	showMatrix(matrix);
	double z = matrix[2][3] / matrix[2][2];
	double y = (matrix[1][3] - z * matrix[1][2]) / matrix[1][1];
	double x = (matrix[0][3] - z * matrix[0][2] - y * matrix[0][1]) / matrix[0][0];

	cout << "X: " << x << endl;
	cout << "Y: " << y << endl;
	cout << "Z: " << z << endl;
}

int main() {
	vector<vector<double>> A = {
		{3,6,9,39},
		{2,5,-2,3},
		{1,3,-1,2}
	};

	gauss(A);

	return 0;
}