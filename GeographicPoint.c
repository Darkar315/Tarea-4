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
  int n = 250;
  int r, i, j;

  int q1, q2, q3, q4;

  int radio;
  int a = 0;

  for (r = 1; r < n; r ++)
  {
    if (a == 1)
    {
      break;
    }
    else
    {
      for (i = (x - r); i <= (x + r); i ++)
      {
	if (a == 1)
	{
	  break;
	}
	else
	{
	  for (j = (y - r); j <= (y + r); j ++)
	  {
	    if (a == 1)
	    {
	      break;
	    }
	    else
	    {
	      q1 = matriz[x + r][y];
	      q2 = matriz[x - r][y];
	      q3 = matriz[x][y + r];
	      q4 = matriz[x][y - r];
	  
	      if (q1 == 1 || q2 == 1 || q3 == 1 || q4 == 1)
	      {
		radio = r - 1;
		a = 1;
	      }
	    
	      else if (matriz[i][j] == 1)
	      {
		radio = r;
		a = 1;
	      }
	    }
	  }
	}
      }
    }
  }
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
