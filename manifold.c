#include <stdlib.h>
#include "manifold.h"

state *new_particle_state (int N, int J)
{
	state *particle = malloc(N * sizeof(state)); 

	for (int n = 0; n < N; n++)
	{
		particle[n].position = new_vector(J); 
		particle[n].newPosition = new_vector(J); 
		particle[n].velocity = new_vector(J); 
		particle[n].newVelocity = new_vector(J); 
		particle[n].newMomentum = new_vector(J); 
	} 

	return particle; 	
}

void initialize_constraints (config manifold) 
{
	manifold.constraint.holonomic = 
		calloc(manifold.K_H, sizeof(double)); 

	manifold.constraint.semiholonomic = 
		calloc(manifold.K_S, sizeof(double)); 

	manifold.constraint.inequality = 
		calloc(manifold.K_I, sizeof(double)); 
}

