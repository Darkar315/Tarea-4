#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

// CONSTANTES GLOBALES

int Nt;
int Nx;
int Ny;

// FUNCIONES

int **Matrix(void);

void Num_init(int *x_x, int *y_y, int **matriz);

int bordes(int a, int i, int N);

void Radio(int **matriz, int x, int y, int *rad);

void liberar_punteros(int **matriz);

// FUNCION MAIN

int main()
{
  Nt = 1000;
  Nx = 500;
  Ny = 744;
  
  int i, j = 0;
  int x, y;
  int rad = 0;

  int **matriz = Matrix();

  Num_init(&x, &y, matriz);
  
  Radio(matriz, x, y, &rad);
  printf("%d\n", rad);
  liberar_punteros(matriz);

  return 0;
}

// CUERPO DE LAS FUNCIONES 

int **Matrix(void)
{
  int i, j = 0;

  int **matriz = malloc(Nx * sizeof(int *));
  
  for (i = 0; i < Nx; i ++)
  {
    matriz[i]= malloc(Ny * sizeof(int));
  }

  FILE *mapa;
  mapa = fopen("map_data.txt", "r");
  
  for (i = 0; i < Nx; i ++)
  {
    for (j = 0; j < Ny; j ++)
    {       
      fscanf(mapa,"%d", &matriz[i][j]);       
    } 
  }
  
  fclose(mapa);
  return matriz;
}

void Num_init(int *x_x, int *y_y, int **matriz)
{
  int minimo = 0;
  
  srand(time(NULL));
   *y_y = rand() % (Ny - minimo) + minimo;
   *x_x = rand() % (Nx - minimo) + minimo;

  while(matriz[*x_x][*y_y] == 1)
  {
    *y_y = rand() % (Ny - minimo) + minimo;
    *x_x = rand() % (Nx - minimo) + minimo;
  }
}

int bordes(int a, int i, int N)
{
  if (a >= N)
  {
    a = a - N + i;
  }
  if (a <= 0)
  {
    a = a + N - i;
  }
  return a;
}

void Radio(int **matriz, int x, int y, int *rad)
{
  int i, j, z;
  int a = 0;
  int r = *rad;
  for (z = 0; z < Nx; z ++)
    {
    for (i = x - z; i < x + z ; i ++)
      {
      for (j = y - z; j < y + z; j ++)
	{
	if (pow((pow(i - x, 2.0) + pow(j - y, 2.0)), 0.5) <= z)
	  {
	  if(matriz[bordes(i, z, Ny)][bordes(j, z, Nx)]==1)
	    {
	    r = i;
	    a = 1;
	    break;	    
	  }
	}
	if(a != 0){break;}
      }
      if(a != 0){break;}
    }
    if(a != 0){break;}
  }
  *rad = r;
}

void liberar_punteros(int **matriz)
{
  int i;
  
  for(i = 0; i < Nx; i ++)
  {
    free(matriz[i]);
  }  
  free(matriz);
}
