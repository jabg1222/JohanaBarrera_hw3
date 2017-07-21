
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>


// Definicion de funciones
// nt es el tiempo total, lo necesario para poder llegar hasta pluton 

int indice( int i, int j)
{
  //int nt=7820928;
  int nt=48*248;
  return (nt*j)+i;
}


float retornamatriz(int filas, int columnas)
{
    FILE *file;
    file=fopen("coordinates.csv", "r");
    int len=250;
    char lineas[len];
    char *separar=NULL;
    const char *delim;
    delim=",";
    
    float val;
    int i=0;
    int j=0;
    float matriz[10][7];

  

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

float Posiciones_X(int index)
{



  int nt=48*248;
  float *Posiciones_X=malloc(10*nt*sizeof(float));
// INICIALIZACION DE LA MATRIZ QUE GUARDA LAS POSICIONES EN X DE LOS PLANETAS
  int i;
for ( i = 0; i < (nt*10); ++i)
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


float Posiciones_Y(int index)
{
  
  int nt=48*248;
  int i;
  float *Posiciones_Y=malloc(10*nt*sizeof(float));
  // INICIALIZACION DE LA MATRIZ QUE GUARDA LAS POSICIONES EN Y DE LOS PLANETAS
for ( i = 0; i < (nt*10); ++i)
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

return Posiciones_Y[index];
}


float Posiciones_Z(int index)
{

 
  int nt=48*248;
  float *Posiciones_Z=malloc(10*nt*sizeof(float));
  int i;

// INICIALIZACION DE LA MATRIZ QUE GUARDA LAS POSICIONES EN Z DE LOS PLANETAS
for ( i = 0; i < (nt*10); ++i)
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

return Posiciones_Z[index];
}

float Velocidades_X(int index)
{

  
  int nt=48*248;
  float *Velocidades_X=malloc(10*nt*sizeof(float));
  int i;

  // INICIALIZACION DE LA MATRIZ QUE GUARDA LAS VELOCIDADES EN X DE LOS PLANETAS
for ( i = 0; i < (nt*10); ++i)
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
  return Velocidades_X[index];
}

float Velocidades_Y(int index)
{
 
  int nt=48*248;
  float *Velocidades_Y=malloc(10*nt*sizeof(float));
  int i;
// INICIALIZACION DE LA MATRIZ QUE GUARDA LAS VELOCIDADES EN Y DE LOS PLANETAS
for ( i = 0; i < (nt*10); ++i)
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

return Velocidades_Y[index];
}

float Velocidades_Z(int index)
{
  //int nt=7820928;
  int nt=48*248;
  int i;
  float *Velocidades_Z=malloc(10*nt*sizeof(float));
  // INICIALIZACION DE LA MATRIZ QUE GUARDA LAS VELOCIDADES EN Z DE LOS PLANETAS
for ( i = 0; i < (nt*10); ++i)
{
  if (i<=9)
  {
    Velocidades_Z[i]=retornamatriz(i,6);
  }
  else
  {
    Velocidades_Z[i]=0;
  }
  //printf("%e\n", Posiciones_X[0] );
  
}
return Velocidades_Z[index];
}

float masas(int index)
{
    float masas[10];
    int a=10;
    int b=30;
    float Masa_Solar;
    Masa_Solar=1.9891*pow(a,b);
    int i;
    


// CALCULA LAS MASAS EN UNIDADES DE AU
for ( i = 0; i < 10; ++i)
{
  masas[i]=(retornamatriz(i,0)/Masa_Solar);
  //printf("%e\n", masas[i] );
}

  return masas[index];
}

float Aceleracion_X( int plt, int ins_t)
{

  float ac=0.0;
  float r=0.0;
  int num_planetas=10;
  int ii;
  const float G= 4*pow(3.141592, 2);

  for ( ii = 0; ii < num_planetas ; ++ii)
  {
    r= pow( Posiciones_X(indice(plt, ins_t)) - Posiciones_X(indice(ii, ins_t)), 2.0) + pow( Posiciones_Y(indice(plt, ins_t)) - Posiciones_Y(indice(ii, ins_t)) , 2.0)+pow( Posiciones_Z(indice(plt, ins_t))-Posiciones_Z(indice(ii, ins_t)) , 2.0);

    //printf("%e\n", r );
      if ( plt != ii)
      {
        ac=ac+((G*masas(ii)*(Posiciones_X(indice(plt, ins_t))- Posiciones_X(indice(ii, ins_t))))/pow(r,1.5));
        printf("%e\n", ac );
      }
      
    
  }


  return ac;
}


float Aceleracion_Y( int plt, int ins_t)
{

  float ac=0.0;
  int nt=48*248;
  float r=0.0;
  int num_planetas=10;
  const float G= 4*pow(3.141592, 2);
  int ii;
  for ( ii = 0; ii < num_planetas ; ++ii)
  {
    
      if ( plt != ii)
      {
        r= pow( Posiciones_X(indice(plt, ins_t)) - Posiciones_X(indice(ii, ins_t)), 2.0) + pow( Posiciones_Y(indice(plt, ins_t)) - Posiciones_Y(indice(ii, ins_t)) , 2.0)+pow( Posiciones_Z(indice(plt, ins_t))-Posiciones_Z(indice(ii, ins_t)) , 2.0);
        ac+=(G*masas(ii)*(Posiciones_Y(indice(plt, ins_t))- Posiciones_Y(indice(ii, ins_t))))/pow(r,3/2);
      }
      
    
  }


  return ac;
}


float Aceleracion_Z( int plt, int ins_t)
{

  float ac=0.0;
  int nt=48*248;
  int num_planetas=10;
  int ii;
  const float G= 39.478417;
  
 
  for ( ii = 0; ii < num_planetas ; ++ii)
  {
    
    float r= pow( Posiciones_X(indice(plt, ins_t)) - Posiciones_X(indice(ii, ins_t)), 2.0) + pow( Posiciones_Y(indice(plt, ins_t)) - Posiciones_Y(indice(ii, ins_t)) , 2.0)+pow( Posiciones_Z(indice(plt, ins_t))-Posiciones_Z(indice(ii, ins_t)) , 2.0);

      if ( plt != ii)
      {
       ac+=((G*masas(ii)*(Posiciones_Z(indice(plt, ins_t))- Posiciones_Z(indice(ii, ins_t))))/pow(r,3/2));
      }
      
    
  }


  return ac;
}




int main(void)
{
  
  int nt=48*248;
  int i;
  int j;
  double *Vel_inter_x=malloc(10*sizeof(double));
  double *Vel_inter_y=malloc(10*sizeof(double));
  double *Vel_inter_z=malloc(10*sizeof(double));
  double dt=(1.0/48.0);
  double *acel_x=malloc(10*sizeof(double));
  double *acel_y=malloc(10*sizeof(double));
  double *acel_z=malloc(10*sizeof(double));
  int num_planetas=10;
  int t;
 
 //
  for(t=1; t<nt-1; ++t)
    {
     
    



          for ( i = 0; i < (10); ++i)
      {

        int presente=indice(i,t);
        int anterior=indice(i,t-1);

       
        
        Vel_inter_x[i]= Velocidades_X(anterior) + (0.5*Aceleracion_X(0,t-1)*dt);
        Vel_inter_y[i]= Velocidades_Y(anterior) + (0.5*Aceleracion_Y(0,t-1)*dt);
        Vel_inter_z[i]= Velocidades_Z(anterior) + (0.5*Aceleracion_Z(0,t-1)*dt);
      


        double Pos_x=Posiciones_X(presente);
        double Pos_y=Posiciones_Y(presente);
        double Pos_z=Posiciones_Z(presente);


        Pos_x = Posiciones_X(anterior)+(Vel_inter_x[i]*dt);
        Pos_y = Posiciones_Y(anterior)+(Vel_inter_y[i]*dt);
        Pos_z = Posiciones_Z(anterior)+(Vel_inter_z[i]*dt);
      
  
      }
      for ( i = 0; i < (10); ++i)
      {
        int presente=indice(i,t);
        int anterior=indice(i,t-1);

        double vel_x=Velocidades_X(presente);
        double vel_y=Velocidades_X(presente);
        double vel_z=Velocidades_X(presente);
        
        vel_x=Vel_inter_x[i]+(0.5*Aceleracion_X(0,t)*dt);
        vel_y=Vel_inter_y[i]+(0.5*Aceleracion_Y(0,t)*dt);
        vel_z=Vel_inter_z[i]+(0.5*Aceleracion_Z(0,t)*dt);
        
      } 
      

    }


 return 0;

}
  