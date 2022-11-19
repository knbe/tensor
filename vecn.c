#include <math.h>
#include "vecn.h"

VecN vecn_new(int dimension) {
	VecN v1; 
	v1.J = dimension; 
	v1.q = calloc(dimension, sizeof(double)); 
	return v1; 
}

VecN vecn_add(VecN v1, VecN v2) {
	VecN v3 = vecn_new(v1.J); 
	for (int j = 0; j < v1.J; j++) {
		v3.q[j] = v1.q[j] + v2.q[j]; 
	}
	return v3; 
}

#if 0
VecN vecn_add3(VecN v1, VecN v2, VecN v3) {
	VecN v4 = vecn_new(v1.J); 
	for (int j = 0; j < v1.J; j++) {
		v4.q[j] = v1.q[j] + v2.q[j] + v3.q[j]; 
	}
	return v4; 
}

VecN vecn_subt(VecN v1, VecN v2) {
	VecN v3 = vecn_new(v1.J); 
	for (int j = 0; j < v1.J; j++) {
		v3.q[j] = v2.q[j] - v1.q[j]; 
	}
	return v3; 
}

VecN vecn_mult(VecN v1, double k) {
	VecN v2 = vecn_new(v1.J); 
	for (int j = 0; j < v1.J; j++) {
		v2.q[j] = v1.q[j] * k; 
	}
	return v2; 
}

VecN vecn_div(VecN v1, double k) {
	VecN v2 = vecn_new(v1.J); 
	for (int j = 0; j < v1.J; j++) {
		v2.q[j] = v1.q[j] / k; 
	}
	return v1; 
}

double vecn_dot(VecN v1, VecN v2) {
	double dotProduct = 0; 
	for (int j = 0; j < v1.J; j++) {
		dotProduct += v1.q[j] * v2.q[j]; 
	}
	return dotProduct; 
}

double vecn_magsq(VecN v1) {
	double magnitudeSq; 
	for (int j = 0; j < v1.J; j++) {
		magnitudeSq += v1.q[j] * v1.q[j]; 
	}
	return magnitudeSq; 
}

double vecn_mag(VecN v1) {
	return sqrt(vecn_magsq(v1)); 
}

VecN vecn_unit(VecN v1) {
	double magnitude = vecn_mag(v1); 
	VecN unit = vecn_div(v1, magnitude); 
	return unit; 
}
#endif
