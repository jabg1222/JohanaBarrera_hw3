
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(void)
{

  FILE *file;
  file=fopen("coordinates.csv", "r");
  int len=1000;
  char lineas[len];
  char *separar=NULL;
  const char *delim;
  delim=",";
  double matriz[10][7];
  double val;
  int i=0;
  int j=0;
  int c;
  int f=1;
  double pos[10][1];

  /*
 for(i=0; i<8; i++){
 
    for (j=0; j<10; j++){
  //fgets(lineas,len,file);
  //separar=strtok(lineas, delim);
  //printf("linea es: %s\n", separar);
   //Use lf format specifier, %c is for character
if (!fscanf(file, "%s", lineas)){ 
break;}
      // mat[i][j] -= '0'; 
    printf("%s\n", lineas);
    
     separar=strtok(lineas, delim);
    separar=strtok(NULL, delim);
    printf("el item es: %s\n", separar );
 	//for (j=0; j<8; j++){
    //matriz[i][j]=1.0;
 		//printf("%e\t", matriz[i][j]);
 	}
 	//printf("\n");
 }
 */

  while(fgets(lineas,len,file) )
{
  //printf("%s\n",lineas );
  separar=strtok(lineas,delim);
    while(separar !=NULL){
      
      
      //printf("el trozo es :%s\n", separar );
      val= atof(separar);
      //printf("en doble es: %e\n", val);
      
      
      
      
      
      matriz[i][j]=val;
      printf("%e\t", matriz[i][j] );
      
      separar=strtok(NULL, delim);
      if (j>=0 && j<=7){
      j=j+1;
    }
    }
    printf("\n");
    if(i>=0 && i<=9){
    i=i+1;
  }
}

while (f<2){
  for(c=0; c<10; c++){
    pos[c][f-1]=matriz[c][f];

  }

  f=f+1;
}
printf("%e\n", pos[1][1]);
 return 0; 
}

