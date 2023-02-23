#ifndef MANIFOLD_H
#define MANIFOLD_H

#include "vector.h"

typedef struct state {
	double mass; 
	vector position;
	vector newPosition; 	
	vector velocity;
        vector newVelocity; 	
	vector momentum;
	vector newMomentum; 	
} state;

typedef struct config {
	int N;			/* number of particles */  
	int J;			/* number of coordinates */  
	int K_H;		/* number of holonomic constraints */ 
       	int K_S; 		/* number of semiholonomic constraints */
	int K_I; 		/* number of inequality constraints */ 	
	state *particle;
	union {
		double *holonomic; 
		double *semiholonomic; 
		double *inequality;
	} constraint;
       	union {
		double G; 
		double E; 
		double B; 
		double EPS_0; 
		double MU_0; 
	} parameter; 	
} config; 

typedef struct simulation {
	double DT;		/* time step */  
	double TT;		/* total run time */ 
        double NT; 		/* number of time points */ 	
	char *initSpecifier; 	/* initial conditions file specifier */ 
} simulation; 

state *new_particle_state (int N, int J);

void initialize_constraints (config manifold);  

#endif
