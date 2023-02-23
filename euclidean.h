#ifndef EUCLIDEAN_H
#define EUCLIDEAN_H

#include <math.h>

//#define DIMENSION(dim) typedef struct uvector ## dim { \
//	double hat[dim]; \
//} uvector ## dim
//
//#define BASIS(dim, ...) typedef struct basis ## dim { \
//	uvector ## dim e[dim]; \
//	struct { __VA_ARGS__ }; \
//} basis ## dim

typedef double scalar; 

#define DIMENSION(dim) \
typedef double cmatrix[dim]; \
typedef struct uvector { \
	scalar mag; \
	cmatrix hat; \
} uvector

#define VECTOR(dim, ...) typedef union vector ## dim { \
	uvector e[dim]; \
	struct { __VA_ARGS__ }; \
} vector ## dim

#define CARTESIAN_31 \
	uvector x; \
	uvector y; \
	uvector z;

#define TENSOR(dim, rank, ...) typedef struct tensor ## dim ## rank { \
	scalar mag[dim * rank]; 
}

#define BASIS(dim, ...) typedef struct basis ## dim { \
	double mag; \
	double hat[dim]; \
} basis ## dim

#define VECTOR(dim, ...) typedef union vector ## dim { \
	basis ## dim e[dim]; \
	struct { __VA_ARGS__ }; \
} vector ## dim

#define TENSOR(dim, rank, ...) typedef union tensor ## dim ## rank { \
	basis ## dim e[pow(dim, rank)]; \
	struct { __VA_ARGS__ }; \
} tensor ## dim ## rank


#define CARTESIAN_31 \
	basis3 x; \
	basis3 y; \
	basis3 z;

#define CARTESIAN_32 \
	double xx; \
	double xy; \
	double xz; \
	double yx; \
	double yy; \
	double yz; \
	double zx; \
	double zy; \
	double zz; 

#define POLAR_31 \
	double r; \
	double theta; \
	double phi; 

#endif
