#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ROWS		100
#define COLUMNS		100

int main( int argc, char **argv )
{

	int			i,j,k,m;
	FILE			*fp;
	float			u, var,sum,sum2,I[99][99];
	unsigned char	image[ROWS][COLUMNS];
  	char			*ifile, *ofile, ch;
	char			filename[4][50];

	strcpy(filename[0], "image1.raw");
	strcpy(filename[1], "image2.raw");
	strcpy(filename[2], "image3.raw");
	strcpy(filename[3], "image4.raw");



	//Assign each image name in filename to ifile here	
	/* example: ifile = filename[k]; k=0,1,2,3; a loop might be need*/
	for (m = 0; m < 4; m++)
	{
		ifile = filename[m];


		if ((fp = fopen(ifile, "rb")) == NULL)
		{
			fprintf(stderr, "error: couldn't open %s\n", ifile);
			exit(1);
		}

		for (i = 0; i < ROWS; i++)
			if (fread(image[i], 1, COLUMNS, fp) != COLUMNS)
			{
				fprintf(stderr, "error: couldn't read enough stuff\n");
				exit(1);
			}

		fclose(fp);

		//Calculate Mean for each image here

		sum = 0;
		for (j = 0; j < ROWS; j++)
		{
			for (k = 0; k < COLUMNS; k++)
				sum += image[j][k];
		}

		u = sum * 1.0 / (ROWS*COLUMNS);

		//printf("Mean = %f ", u);

//Calculate Variance for each image here

		sum2 = 0;
		for (j = 0; j < ROWS; j++)
		{
			for (k = 0; k < COLUMNS; k++)
				sum2 += pow(image[j][k] - u, 2);
		}

		var = sum2 * 1.0 / (ROWS*COLUMNS - 1);

		//printf("Mean = %f ", u);	

//Print mean and variance for each image
		printf("%s: u=%f var=%f\n", ifile, u, var);

		printf("Press any key to exit: ");
		gets(&ch);
	}
	return 0;

}


