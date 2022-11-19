#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "manifold.h"

int main ()
{
	int N; 	/* number of particles */ 
	int J;	/* number of coordinates */ 
       	int K;	/* number of constraints */ 	


	/* create vector */

	J = 3;

	vector force = new_vector(J); 

	force.coordinate[0] = 0; 
	force.coordinate[1] = -9.81; 
	force.coordinate[2] = 0; 

	printf("\nnew vector\nelements:\n\n"); 

	for (int j = 0; j < J; j++)
		printf("%f\n", force.coordinate[j]); 


	/* create vector array */

	N = 2; J = 3; 

	vector *position = new_vector_array(N, J);

	position[0].coordinate[1] = 0.707; 
	position[1].coordinate[2] = 1.414; 

	printf("\nnew vector array\nelements:\n\n");

	for (int n = 0; n < N; n++)
	{
		printf("particle %d:\n", n); 
		
		for (int j = 0; j < J; j++)
		{
			printf("%f\n", position[n].coordinate[j]);
		}
	}


	/* add two vectors */

	vector r1 = new_vector(J);
	vector r2 = new_vector(J); 

	r1.coordinate[0] = 1; 
	r1.coordinate[1] = 1; 
	r1.coordinate[2] = 1; 

	r2 = vector_add(r1, position[1]);

	printf("\ntest vector add 2\nelements:\n\n"); 

	for (int j = 0; j < J; j++)
		printf("%f\n", r2.coordinate[j]); 


	/* create system of particles */

	config manifold;

	manifold.N = 3; 
	manifold.J = 3; 
	manifold.K_H = 2; 
	manifold.K_S = 0; 
	manifold.K_I = 0;

	manifold.particle = new_particle_state (
		manifold.N, manifold.J);

	initialize_constraints (manifold); 	


	/* add manifold vector */ 

	manifold.particle[2].position.coordinate[1] = 2.1;

	printf("\ntest manifold vector add 2\nelements:\n\n"); 

	vector r3 = vector_add(r2, manifold.particle[2].position); 

	for (int j = 0; j < J; j++) 
	{
		printf("%f\n", r3.coordinate[j]);
	}

	
	/* end */ 	

	printf("\n"); 	
}

