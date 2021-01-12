#include "pch.h"
#include "deltaRule.h"
#include <cmath>
#include "Process.h"


int deltaRule(Samples sample, double* weights, double c) {
	float bias = 1, net = 0, output = 0.0, desired_output = (int)sample.id;

	// net = w[0]*x1 + w[1].x2 + w[2]*bias

	net += sample.x1 * weights[0];
	net += sample.x2 * weights[1];
	net += bias * weights[2];

	// output = f(net)

	output = sigmoid(net);

	// w(t + 1) = w(t) * delta_w

	if (!IS_EQUAL(output, desired_output)) {
		weights[0] = weights[0] + c * (desired_output - output) * sigmoidDerivative(net) * sample.x1;
		weights[1] = weights[1] + c * (desired_output - output) * sigmoidDerivative(net) * sample.x2;
		weights[2] = weights[2] + c * (desired_output - output) * sigmoidDerivative(net) * bias;
		return 0;
	}
	else {
		return 1;
	}
}



