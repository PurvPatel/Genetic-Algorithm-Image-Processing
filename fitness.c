#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "a4.h"

double comp_distance(const PIXEL *A, const PIXEL *B, int image_size)
{
	double distance = 0;
	for (int i = 0; i < image_size; i++)
	{
		distance += (A[i].r - B[i].r)*(A[i].r - B[i].r);
		distance += (A[i].g - B[i].g)*(A[i].g - B[i].g);
		distance += (A[i].b - B[i].b)*(A[i].b - B[i].b);
	}

	distance = sqrt(distance);
	return distance;
}
void comp_fitness_population(const PIXEL *image, Individual *individual, int population_size)
{
	int width = individual[0].image.width;
	int height = individual[0].image.height;
	for (int i = 0; i < population_size;i++)
		individual[i].fitness = comp_distance(image, individual[i].image.data,width*height);
}