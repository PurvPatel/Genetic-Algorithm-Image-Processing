#include "a4.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

static int split(Individual *a, int low, int high)
{
	double pivot = a[high].fitness; 
	int j, i = low;
	Individual temp;

	for(j = low; j < high; j++)
	{
		if(a[j].fitness <= pivot)
		{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
		}
	}
	temp = a[i];
	a[i] = a[high];
	a[high] = temp;
	return i;
}

static void quicksort(Individual *population, int low, int high)
{
	if(low > high)
		return;
	int index = split(population, low, high);
	quicksort (population, low, index - 1);
	quicksort (population, index + 1, high);
}
PPM_IMAGE *evolve_image(const PPM_IMAGE *image, int num_generations, int population_size, double rate)
{
	srand(time(NULL));
	PPM_IMAGE *new_image = malloc(sizeof(PPM_IMAGE));
	int width = image->width, height = image->height, max_color = image->max_color;

	Individual *population = generate_population(population_size, width, height, max_color);
 	comp_fitness_population(image->data, population, population_size);
 	quicksort(population, 0, population_size-1);

 	for(int i = 0; i < num_generations; i++)
 	{
 		crossover(population, population_size);
 		mutate_population(population, population_size, rate);
 		comp_fitness_population(image->data, population, population_size);
 		quicksort(population, 0, population_size-1);
 	}

 	*new_image = population->image;

 	for(int i = 1; i < population_size;i++)
 	{
 		free(population[i].image.data);
 	}

 	free(population);
 	return new_image;
}

void free_image(PPM_IMAGE *p)
{
	free(p->data);	
	free(p);
	return;
}