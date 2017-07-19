
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>


int indice( int i, int j, int N)
{
  return (N*j)+i;
}


double retornamatriz(int filas, int columnas)
{
    FILE *file;
    file=fopen("coordinates.csv", "r");
    int len=250;
    char lineas[len];
    char *separar=NULL;
    const char *delim;
    delim=",";
    
    double val;
    int i=0;
    int j=0;
    double matriz[10][7];

  

// LEE EL ARCHIVO Y LO GUARDA EN LA MATRIZ
  while(fgets(lineas,len,file) )
{
  //printf("%s\n",lineas );
  j=0;
  separar=strtok(lineas,delim);
    while(separar !=NULL)
    {
      if(j !=0)
      {
      
      //printf("el trozo es :%s\n", separar );
        val= atof(separar);
      //printf("en doble es: %e\n", val);
        matriz[i][j-1]=val;
      //printf("%e\t", val );
      }
      
      separar=strtok(NULL, delim);
      
      if (j>=0 && j<=6)
      {
        j=j+1;
      }
      
    }
    //printf("\n");
    if(i>=0 && i<=9)
    {
      i=i+1;
    }
}

return matriz[filas][columnas];

}

double Posiciones_X(int index)
{


int nt=30;
double *Posiciones_X=malloc(10*nt*sizeof(double));
// INICIALIZACION DE LA MATRIZ QUE GUARDA LAS POSICIONES EN X DE LOS PLANETAS
for (int i = 0; i < (nt*10); ++i)
{
  if (i<=9)
  {
    Posiciones_X[i]=retornamatriz(i,1);
  }
  else
  {
    Posiciones_X[i]=0;
  }
  //printf("%e\n", Posiciones_X[i] );  
}

return Posiciones_X[index];
}


double Posiciones_Y(int index)
{
  int nt=30;
  double *Posiciones_Y=malloc(10*nt*sizeof(double));
  // INICIALIZACION DE LA MATRIZ QUE GUARDA LAS POSICIONES EN Y DE LOS PLANETAS
for (int i = 0; i < (nt*10); ++i)
{
  if (i<=9)
  {
    Posiciones_Y[i]=retornamatriz(i,2);
  }
  else
  {
    Posiciones_Y[i]=0;
  }
  //printf("%e\n", Posiciones_X[i] );
}
}


double Posiciones_Z(int index)
{

  int nt=30;
  double *Posiciones_Z=malloc(10*nt*sizeof(double));


// INICIALIZACION DE LA MATRIZ QUE GUARDA LAS POSICIONES EN Z DE LOS PLANETAS
for (int i = 0; i < (nt*10); ++i)
{
  if (i<=9)
  {
    Posiciones_Z[i]=retornamatriz(i,3);
  }
  else
  {
    Posiciones_Z[i]=0;
  }
  //printf("%e\n", Posiciones_X[i] );
}
}

double Velocidades_X(int index)
{

  int nt=30;
  double *Velocidades_X=malloc(10*nt*sizeof(double));


  // INICIALIZACION DE LA MATRIZ QUE GUARDA LAS VELOCIDADES EN X DE LOS PLANETAS
for (int i = 0; i < (nt*10); ++i)
{
  if (i<=9)
  {
    Velocidades_X[i]=retornamatriz(i,4);
  }
  else
  {
    Velocidades_X[i]=0;
  }
  //printf("%e\n", Posiciones_X[i] );
}
}

double Velocidades_Y(int index)
{
  int nt=30;

  double *Velocidades_Y=malloc(10*nt*sizeof(double));

// INICIALIZACION DE LA MATRIZ QUE GUARDA LAS VELOCIDADES EN Y DE LOS PLANETAS
for (int i = 0; i < (nt*10); ++i)
{
  if (i<=9)
  {
    Velocidades_Y[i]=retornamatriz(i,5);
  }
  else
  {
    Velocidades_Y[i]=0;
  }
  //printf("%e\n", Posiciones_X[i] );
}


}

double Velocidades_Z(int index)
{
  int nt=30;
  double *Velocidades_Z=malloc(10*nt*sizeof(double));
  // INICIALIZACION DE LA MATRIZ QUE GUARDA LAS VELOCIDADES EN Z DE LOS PLANETAS
for (int i = 0; i < (nt*10); ++i)
{
  if (i<=9)
  {
    Velocidades_Z[i]=retornamatriz(i,6);
  }
  else
  {
    Velocidades_Z[i]=0;
  }
  //printf("%e\n", Posiciones_X[i] );
}
}

int main(void)
{

  double a;
  double b;
  a=Posiciones_X(indice(3,0, 30));
  b=retornamatriz(3,1);

  printf("%e\n %e\n", a, b);


 return 0; 
}


/*
double Aceleracion_x( int plt, int ins_t)
{
  double masas[10];
  int a=10;
  int b=30;
  double Masa_Solar;
  Masa_Solar=1.9891*pow(a,b);
  const int G= 4*pow(3.141592, 2);


// CALCULA LAS MASAS EN UNIDADES DE AU
for (int i = 0; i < 10; ++i)
{
  masas[i]=(retornamatriz(i,0)/Masa_Solar);
  //printf("%e\n", masas[i] );
}

  double acx;
  int nt=30;
  int num_planetas=10;
  for (int ii = 0; ii < num_planetas ; ++ii)
  {
    for (int ins_t = 0; ins_t < nt; ++ins_t)
    {
      double r= pow((Posiciones_X(indice(plt, ins_t))-Posiciones_X(indice(ii, ins_t)),2)+pow((Posiciones_Y(indice(plt, ins_t))-Posiciones_Y(indice(ii, ins_t)]),2)+pow((Posiciones_Z(indice(plt, ins_t))-Posiciones_Z(indice(ii, ins_t)),2);
      acx=(G*retornamatriz[ii][0])/(pow(r,(3/2)));
    }
  }
}
 */ 

