#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// CONSTANTES GLOBALES

int Nt;
int Nx;
int Ny;

// FUNCIONES

int **Matrix(void);

int Radio(int **matriz, int x, int y);

void Pasos(int **matriz, int *x, int *y);

//int Periodico();

// FUNCION MAIN

int main(void)
{
  int i, j = 0;

  int filas;
  int cols;

  Nt = 10000;
  Nx = 500;
  Ny = 744;

  int **matriz = Matrix();

  Pasos(matriz, &filas, &cols);

  int radio = Radio(matriz, filas, cols);

  printf("%d\n", radio);
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
  int r = 250;
  int radio;

  int q1, q2, q3, q4;
  int c1, c2, c3, c4;

  for (z = 1; z < r; z ++)
  {
    for (i = 1; i < z; i ++)
    {
      for (j = 1; j < z; j ++)
      {
	//z = pow(pow(i, 2.0) + pow(j, 2.0), 0.5);
	
	q1 = matriz[x + i][y + j];
	q2 = matriz[x - i][y + j];
	q3 = matriz[x - i][y - j];
	q4 = matriz[x + i][y - j];
	
	if (q1 == 1 || q2 == 1 || q3 == 1 || q4 == 1)
	{
	  radio = z;
	  break;
	}
      }
    }
  }
  return radio;
}

void Pasos(int **matriz, int *x, int *y)
{
  int i;
  
  srand(time(NULL));
  *x = (rand() % (Nx + 1));
  *y = (rand() % (Ny + 1));
  
  while (matriz[*x][*y] != 0)
  {
    *x = (rand() % (Nx + 1));
    *y = (rand() % (Ny + 1));
  }

  /*for (i = 0; i < Nt; i ++)
  {
    int pasos = (rand() % (50 + 1 - 50)) + 50;
    *x = *x + pasos;
    *y = *y + pasos;
  }
  */
}
