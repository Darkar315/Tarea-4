#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// CONSTANTES GLOBALES

#define Nt 10000

int Nx;
int Ny;

// FUNCIONES

int **Matrix(void);

double Radio(int x, int y);

void Pasos(int **matriz, int *x, int *y);

//int Periodico();

// FUNCION MAIN

int main(void)
{
  int i, j = 0;

  int filas;
  int cols;

  Nx = 500;
  Ny = 744;

  int **matriz = Matrix();

  Pasos(matriz, &filas, &cols);

  printf("%d %d\n", filas, cols);
}

// CUERPO DE LAS FUNCIONES 

int **Matrix(void)
{
   int i, j = 0;

   FILE *mapa;
   mapa = fopen("map_data.txt", "r");

   int **matrix = malloc(Nx * Ny * sizeof(float));

   for (i = 0; i < Nx; i ++)
   {
     matrix[i] = malloc(Ny * sizeof(int));
     for (j = 0; j > Ny; j ++)
     {
      fscanf(mapa, "%d", &matrix[i][j]);
     }
   }

   fclose(mapa);
   return matrix;
}

int Radio(int **matriz, int x, int y)
{
  int i, j, z;
  int r = 10;

  for (z = -r; z < r: z ++)
  {
    for (i = 1; i < r; i ++)
    {
      for (j = 1; j < r; j ++)
      {
	matriz[x + i][y + j];
	matriz[x - i][y + j];
	matriz[x - i][y - j];
	matriz[x + i][y - j];
	
	int radio = pow(i - x, 2.0) + pow(j - y, 2.0);
	if ()
	{
	  
	}
      }
    }
  }
}

void Pasos(int **matriz, int *x, int *y)
{
  srand(time(NULL));
  *x = (rand() % (Nx + 1));
  *y = (rand() % (Ny + 1));
  
  while (matriz[*x][*y] != 0)
  {
    *x = (rand() % (Nx + 1));
    *y = (rand() % (Ny + 1));
  }
  
  int pasos = (rand() % (50 + 1 - 50)) + 50;
  *x = *x + pasos;
  *y = *y + pasos;
}
