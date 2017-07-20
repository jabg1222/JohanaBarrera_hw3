
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<math.h>


int indice( int i, int j)
{
  //int nt=7820928;
  int nt=48*248;
  return (nt*j)+i;
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


//int nt=7820928;
  int nt=48*248;
double *Posiciones_X=malloc(10*nt*sizeof(double));
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


double Posiciones_Y(int index)
{
  //int nt=7820928;
  int nt=48*248;
  int i;
  double *Posiciones_Y=malloc(10*nt*sizeof(double));
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


double Posiciones_Z(int index)
{

  //int nt=7820928;
  int nt=48*248;
  double *Posiciones_Z=malloc(10*nt*sizeof(double));
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

double Velocidades_X(int index)
{

  //int nt=7820928;
  int nt=48*248;
  double *Velocidades_X=malloc(10*nt*sizeof(double));
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
}

double Velocidades_Y(int index)
{
  //int nt=7820928;
  int nt=48*248;
  double *Velocidades_Y=malloc(10*nt*sizeof(double));
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


}

double Velocidades_Z(int index)
{
  //int nt=7820928;
  int nt=48*248;
  int i;
  double *Velocidades_Z=malloc(10*nt*sizeof(double));
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
  printf("HOLA \n" );
}
}

double masas(int index)
{
    double masas[10];
    int a=10;
    int b=30;
    double Masa_Solar;
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

double Aceleracion_X( int plt, int ins_t)
{

  double ac=0;
  
  int num_planetas=10;
  int ii;
  const double G= 4*pow(3.141592, 2);
 
  for ( ii = 0; ii < num_planetas ; ++ii)
  {
    double r= pow( Posiciones_X(indice(plt, ins_t)) - Posiciones_X(indice(ii, ins_t)), 2.0) + pow( Posiciones_Y(indice(plt, ins_t)) - Posiciones_Y(indice(ii, ins_t)) , 2.0)+pow( Posiciones_Z(indice(plt, ins_t))-Posiciones_Z(indice(ii, ins_t)) , 2.0);
      if ( plt != ii)
      {
        
        ac=ac+((G*masas(ii)*(Posiciones_X(indice(plt, ins_t))- Posiciones_X(indice(ii, ins_t))))/pow(r,1.5));
      }
      
    
  }


  return ac;
}


double Aceleracion_Y( int plt, int ins_t)
{

  double ac=0;
  int nt=48*248;
  int num_planetas=10;
  const double G= 4*pow(3.141592, 2);
  int ii;
  for ( ii = 0; ii < num_planetas ; ++ii)
  {
    
      if ( plt != ii)
      {
        double r= pow( Posiciones_X(indice(plt, ins_t)) - Posiciones_X(indice(ii, ins_t)), 2.0) + pow( Posiciones_Y(indice(plt, ins_t)) - Posiciones_Y(indice(ii, ins_t)) , 2.0)+pow( Posiciones_Z(indice(plt, ins_t))-Posiciones_Z(indice(ii, ins_t)) , 2.0);
        ac+=(G*masas(ii)*(Posiciones_Y(indice(plt, ins_t))- Posiciones_Y(indice(ii, ins_t))))/pow(r,3/2);
      }
      
    
  }


  return ac;
}


double Aceleracion_Z( int plt, int ins_t)
{

  double ac=0;
  int nt=48*248;
  int num_planetas=10;
  int ii;
  const double G= 39.478417;
  
 
  for ( ii = 0; ii < num_planetas ; ++ii)
  {
    
    double r= pow( Posiciones_X(indice(plt, ins_t)) - Posiciones_X(indice(ii, ins_t)), 2.0) + pow( Posiciones_Y(indice(plt, ins_t)) - Posiciones_Y(indice(ii, ins_t)) , 2.0)+pow( Posiciones_Z(indice(plt, ins_t))-Posiciones_Z(indice(ii, ins_t)) , 2.0);

      if ( plt != ii)
      {
       ac+=((G*masas(ii)*(Posiciones_Z(indice(plt, ins_t))- Posiciones_Z(indice(ii, ins_t))))/pow(r,3/2));
      }
      
    
  }


  return ac;
}




int main(void)
{
  
  printf("%e\n", Aceleracion_X(0,0) );
  
//double *Posiciones_X=malloc(10*nt*sizeof(double));


//double h;
//h=Aceleracion(0,0,Posiciones_X);
//printf("%e\n", h);
//printf("%e\n", Aceleracion_Z() );


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
           /*
  for (i=0; i<10; ++i)
    {
      acel_x=Aceleracion_X(i,0);
      acel_y=Aceleracion_Y(i,0);
      acel_z=Aceleracion_Z(i,0);
    }
           */
  /*
  for(t=1; t<nt-1; ++t)
    {
     
    



          for ( i = 0; i < (10); ++i)
      {

        int presente=indice(i,t);
        int anterior=indice(i,t-1);
        acel_x[i]=Aceleracion_X(0,0);
        acel_y[i]=Aceleracion_Y(0,0);
        acel_z[i]=Aceleracion_Z(0,0);
*/
        /*
        Vel_inter_x[presente]= Velocidades_X(anterior) + (0.5*acel_x[anterior])*dt);
        Vel_inter_y[presente]= Velocidades_Y(anterior) + (0.5*acel_y[anterior]*dt);
        Vel_inter_z[presente]= Velocidades_Z(anterior) + (0.5*acel_z[anterior]*dt);


        Posiciones_X(presente) = Posiciones_X(anterior)+(Vel_inter_x[presente]*dt);
        Posiciones_Y(presente) = Posiciones_Y(anterior)+(Vel_inter_y[presente]*dt);
        Posiciones_Z(presente) = Posiciones_Z(anterior)+(Vel_inter_z[presente]*dt);


        Velocidades_X(presente)=Vel_inter_x[presente]+(0.5*acel_x[presente]*dt);
        Velocidades_Y(presente)=Vel_inter_y[presente]+(0.5*acel_y[presente]*dt);
        Velocidades_Z(presente)=Vel_inter_z[presente]+(0.5*acel_z[presente]*dt);
             
        
        
        Vel_inter_x[indice(i,t)]= Velocidades_X(anterior) + (0.5*Aceleracion_X(i,t-1)*dt);
        Vel_inter_y[indice(i,t)]= Velocidades_Y(anterior) + (0.5*Aceleracion_Y(i,t-1)*dt);
        Vel_inter_z[indice(i,t)]= Velocidades_Z(anterior) + (0.5*Aceleracion_Z(i,t-1)*dt);
        */
/*
        
        Vel_inter_x[indice(i,t)]= Velocidades_X(anterior) + (0.5*acel_x[0]*dt);
        Vel_inter_y[indice(i,t)]= Velocidades_Y(anterior) + (0.5*acel_y[0]*dt);
        Vel_inter_z[indice(i,t)]= Velocidades_Z(anterior) + (0.5*acel_x[0]*dt);

        double Pos_x=Posiciones_X(presente);
        double Pos_y=Posiciones_Y(presente);
        double Pos_z=Posiciones_Z(presente);


        Pos_x = Posiciones_X(anterior)+(Vel_inter_x[presente]*dt);
        Pos_y = Posiciones_Y(anterior)+(Vel_inter_y[presente]*dt);
        Pos_z = Posiciones_Z(anterior)+(Vel_inter_z[presente]*dt);
      }

          for ( i = 0; i < (10); ++i)
      {
        int presente=indice(i,t);
        int anterior=indice(i,t-1);

        double vel_x=Velocidades_X(presente);
        double vel_y=Velocidades_X(presente);
        double vel_z=Velocidades_X(presente);
        
        vel_x=Vel_inter_x[presente]+(0.5*Aceleracion_X(i,t)*dt);
        vel_y=Vel_inter_y[presente]+(0.5*Aceleracion_Y(i,t)*dt);
        vel_z=Vel_inter_z[presente]+(0.5*Aceleracion_Z(i,t)*dt);
        
      } 
      

    }
*/
 return 0;

}
  