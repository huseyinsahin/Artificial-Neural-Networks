#include "Process.h"
#include "pch.h"
#include "Resource.h"
#include <cmath>

int YPoint(int x, double* w, int Carpan = 1) {
	return (int)((double)(-1 * (double)Carpan * w[2] - w[0] * x) / (double)(w[1]));
}

double sgn(double net) {

	return (net >= 0.0f) ? 1.0f : (0.0f);
}

double sgnDerivative(double net) {

	return 0.0f;
}

double sigmoid(double net) {

	return (1.0 / (1.0 + pow(euler, -net)));
}

double sigmoidDerivative(double net) {

	return sigmoid(net) * (1 - sigmoid(net));
}