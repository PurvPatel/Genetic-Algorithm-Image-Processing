#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "a4.h"

PIXEL *generate_random_image(int width, int height, int max_color)
{
	PIXEL *pixels = malloc(sizeof(PIXEL)*(width*height));
	for (int i = 0; i < width*height; i++)
	{
		pixels[i].r = (rand() % (max_color + 1));
		pixels[i].g = (rand() % (max_color + 1));
		pixels[i].b = (rand() % (max_color + 1));
	}
	return pixels;
}
Individual *generate_population(int population_size, int width, int height, int max_color)
{
	Individual *pop = malloc(sizeof(Individual)*population_size);

	for(int i = 0; i < population_size; i++)
	{
		(pop[i].image).width = width;
		(pop[i].image).height = height;
		(pop[i].image).max_color = max_color;
		(pop[i].image).data = generate_random_image(width, height, max_color);
	} 
	return pop;
}