//file readwrite PPM
#include "a4.h"
#include <stdlib.h>
#include <stdio.h>

PPM_IMAGE *read_ppm(const char *file_name)
{
	PPM_IMAGE *readfile = malloc(sizeof(PPM_IMAGE));

	FILE *fp = fopen (file_name, "r");

	while(fgetc(fp) != '\n');

	fscanf(fp, "%d", &readfile->width);
	fscanf(fp, "%d", &readfile->height);
	fscanf(fp, "%d", &readfile->max_color);

	PIXEL *blocks = malloc(sizeof(PIXEL)*(readfile->width*readfile->height));
	readfile->data = blocks;
	
	for(int i = 0; i < readfile->width * readfile->height; i++)
	{
		fscanf(fp, "%hhu", &(blocks[i].r));
		fscanf(fp, "%hhu", &(blocks[i].g));
		fscanf(fp, "%hhu", &(blocks[i].b));
	}	

	fclose(fp);
	return readfile; 

}
void write_ppm(const char *file_name, const PPM_IMAGE *image)
{
	FILE *fp = fopen (file_name, "w");

	fprintf(fp, "P3\n");

	fprintf(fp, "%d %d\n", image->width, image->height);
	fprintf(fp, "%d\n", image->max_color);
	
	for(int i = 0; i < image->height * image->width; i++)
	{
		fprintf(fp, "%hhu ", (image->data[i]).r);
		fprintf(fp, "%hhu ", (image->data[i]).g);
		fprintf(fp, "%hhu ", (image->data[i]).b);
	}	

	fclose(fp);
	return;
}