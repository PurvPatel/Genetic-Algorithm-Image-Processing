#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "a4.h"

void mutate(Individual *individual, double rate)
{
	int n = individual[0].image.width * individual[0].image.height, index;
	int pixels_mutated = (int) (rate/100*n); 

	for (int i = 0; i < pixels_mutated; i++)
	{

		index = rand() % n;

		//assigning new random pixel rgb values

		individual->image.data[index].r = (rand() % (individual->image.max_color + 1));
		individual->image.data[index].g = (rand() % (individual->image.max_color + 1));
		individual->image.data[index].b = (rand() % (individual->image.max_color + 1));
	}

	return;
}
void mutate_population(Individual *individual, int population_size, double rate)
{
	for(int i = population_size/4; i < population_size; i++)
		mutate(individual + i, rate);
	return;
}