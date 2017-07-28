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

void Num_init(int *xx, int *yy, int **matriz);

int Per(int z, int N);

int Radio(int **matriz, int x, int y);

//void numeros(int x, int y, int *x1, int *y1, int **matriz);

// FUNCION MAIN

int main()
{
  Nt = 150;
  Nx = 500;
  Ny = 744;
  
  int i, j;
  int x, y;
  int x1, y1;
  int xf, yf;
  int rad = 0;
  int rad1, rad2;

  float a, b;

  int **matriz = Matrix();

  Num_init(&x, &y, matriz);

  rad1 = Radio(matriz, x, y);

  srand(time(NULL));
  for (i = 0; i < Nt; i ++)
  {
    float beta, alpha;

    beta = drand48();

    int pasos = 25;
  
    x1 = x + (rand() % (pasos  - (-pasos) )) + (-pasos);
    y1 = y + (rand() % (pasos - (-pasos) )) + (-pasos);

    while(matriz[Per(x1, Nx)][Per(y1, Ny)] != 0)
    {
      x1 = x + (rand() % (pasos - (-pasos) )) + (-pasos);
      y1 = y + (rand() % (pasos  - (-pasos) )) + (-pasos);
    }

    rad2 = Radio(matriz, x1, y1);

    a = rad1;
    b = rad2;

    if (rad2 > rad)
    {
      rad = rad2;
      xf = x1;
      yf = y1;
    }
    
    alpha = b / a;

    if (alpha >= 1)
    {
      rad1 = rad2;
      x = x1;
      y = y1;
    }
    else
    {
      if (beta <= alpha)
      {
	rad1 = rad2;
	x = x1;
	y = y1;
      }
      else
      {
	continue;
      }
    }
  }
  xf = Per(xf, Nx);
  yf = Per(yf, Ny);

  FILE *datos;
  datos = fopen("datos.txt", "w+");
  
  fprintf(datos, "%d %d %d\n", rad, xf, yf);
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

void Num_init(int *xx, int *yy, int **matriz)
{
  int a=*xx;
  int b=*yy;
  srand(time(NULL));
  a = rand() % Nx;
  b = rand() % Ny;

  while(matriz[a][b] == 1)
  {
    a = rand() % Nx;
    b = rand() % Ny;
  }
  *xx=a;
  *yy=b;
}

int Per(int z, int N)
{
  if (z >= N)
  {
    z = z % N;
  }
  if (z < 0)
  {
    z = z + N;
  }
  return z;
}

int Radio(int **matriz, int x, int y)
{
  int i, j, z;
  int a = 0;
  int r = 0;
  
  for (z = 1; z < Nx; z ++)
    {
    for (i = x - z; i <= x + z ; i ++)
      {
      for (j = y - z; j <= y + z; j ++)
	{
	if (pow((pow(i - x, 2.0) + pow(j - y, 2.0)), 0.5) <= z)
	  {
	  if (matriz[Per(i, Ny)][Per(j, Nx)] == 1)
	    {
	    r = z;
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
  return r;
}

/*void numeros(int x, int y, int *x1, int *y1, int **matriz)
{
  srand(time(NULL));
  int minimo = -50;
  int pasos = (rand() % (50 - minimo)) + minimo;
  
  *x1 = x + (rand() % (pasos  - (-pasos) )) + (-pasos);
  *y1 = y + (rand() % (pasos - (-pasos) )) + (-pasos);

  while(matriz[Per(*x1, Nx)][Per(*y1, Ny)] != 0)
  {
    *x1 = x + (rand() % (pasos - (-pasos) )) + (-pasos);
    *y1 = y + (rand() % (pasos  - (-pasos) )) + (-pasos);
  }
}
*/
