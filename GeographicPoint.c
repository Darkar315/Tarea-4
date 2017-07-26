#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// CONSTANTES GLOBALES

int Nx;
int Ny;

// FUNCIONES

int **Matrix(void);

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
