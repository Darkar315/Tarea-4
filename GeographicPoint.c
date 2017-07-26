#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// CONSTANTES GLOBALES

int Nx;
int Ny;

// FUNCIONES

int **Matrix(void);

double Radio(int x, int y);

int Num_random(int **matriz);

// FUNCION MAIN

int main(void)
{
  int i, j = 0;

  Nx = 500;
  Ny = 744;

  int **matriz = Matrix();
}

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
   return matrix;
}

double Radio(int x, int y)
{
  double r = 0;
  r = pow(x, 2.0) + pow(y, 2.0);
  return r;
}

int Num_random(int **matriz)
{
  int filas;
  int cols;

  int i;
  int j;
  double alpha;

  srand(time(NULL));
  for (i = 0; i < Nx; i ++)
  {
    int filas = (rand() % (Nx + 1));
    for (j = 0; j < Ny; j ++)
    {
      int cols = (rand() % (Ny + 1));
      if (matriz[filas][cols] == 0)
      {
	/////////////////////////////////////////////////////////////
      }
    }
  }
}
