# Primer punto: Tarea 3


import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation

Tiempo=[] # Se inicializa una lista vacia, en donde se va a guardar cada instante que pasa cuando evoluciona la onda.

# Se define una funcion para poder realizar las graficas t=60 y t=30 facilmente.

def Onda( tiempo_total, inst_Tiempo ):
	

# Se determinan las constantes necesarias para resolver el ejercicio-

	pts=300 #La grilla debe ser de 300 puntos segun el enunciado

	alfa=0.5 # Por la condicion de estabilidad alfa debe ser menor o igual a 0.5

	a=0. # es el limite minimo de la caja
	b=30. #  limite maximo de la caja
	dx_dy=(b-a)/float(pts-1) # En este caso dx y dy van a ser iguales


	c=1.
	dt=(alfa**(1./2.)*(dx_dy/c)) # a partir del dx,dy se calcula el dt
	r=c*(dt/dx_dy)

# En primer lugar se establecen las condiciones iniciales de la Onda contenida en la caja.

	u_inicial=np.zeros((pts,pts)) # Es la ondas en el tiempo cero.
	u_inicial[(pts/3)-1, (pts/2)-1]=-0.5

# Extremos
	u_inicial[:,0]=0
	u_inicial[0,:]=0
	u_inicial[:,-1]=0
	u_inicial[-1,:]=0
	u_inicial[((pts*2)/3)-1, :((pts/2)-pts/20)]=0 #Rendija
	u_inicial[((pts*2)/3)-1 ,((pts/2)+(pts/20)+1):]=0 #Rendija


	u_futuro=np.copy(u_inicial) # Se hace una copia de la matriz inicial para poder guardar ahi el tiempo en el instante sigiente.




# A continuacion se calcula la primeta iteracion, es decir el sigiente instante de tiempo y se guarda en u_futuro, procurando que los extremos y donde se encuentra la rendija permanezcan en cero.
	for i in range(1,pts-1):
		for j in range(1,pts-1):
			u_futuro[i,j]=(u_inicial[i,j]+(r**2/2.0)*(u_inicial[i+1,j]-2.0*u_inicial[i,j]+u_inicial[i-1,j]))+(u_inicial[i,j]+(r**2/2.0)*(u_inicial[i,j+1]-2.0*u_inicial[i,j]+u_inicial[i,j-1]))
			u_futuro[:,0]=0
			u_futuro[0,:]=0
			u_futuro[:,-1]=0
			u_futuro[-1,:]=0
			u_futuro[((pts*2)/3)-1, :((pts/2)-pts/30)]=0
			u_futuro[((pts*2)/3)-1 ,((pts/2)+(pts/30)+1):]=0

# Se crean estas matrices para poder luego actualizar posteriormente.
	u_pasado=np.copy(u_inicial)
	u_presente=np.copy(u_futuro)
	inst_Tiempo.append(u_presente) #Se agrega el tiempo t=1 a la lista

# Siguientes iteraciones

	iteraciones= tiempo_total/dt

	for t in range(1,int(iteraciones)):
 		for i in range(1,pts-1):
 			for j in range(1, pts-1):
 				u_futuro[i,j]= (alfa**2*(u_presente[i+1,j]-2*u_presente[i,j]+u_presente[i-1,j]+u_presente[i,j+1]-2*u_presente[i,j]+u_presente[i,j-1]))+(2*u_presente[i,j])-(u_pasado[i,j])
 		u_futuro[:,0]=0
		u_futuro[0,:]=0
		u_futuro[:,-1]=0
		u_futuro[-1,:]=0
		u_futuro[((pts*2)/3)-1, :((pts/2)-pts/30)]=0
		u_futuro[((pts*2)/3)-1 ,((pts/2)+(pts/30)+1):]=0
 		u_pasado=np.copy(u_presente)
 		u_presente=np.copy(u_futuro)
		inst_Tiempo.append(u_presente)

	return u_presente, inst_Tiempo

# Graficas de t=60 y t=30
t_60=Onda(60, Tiempo)[0]
t_30=Onda(30, Tiempo)[0]

plt.imshow(t_60)
plt.savefig("Onda_t60.png")
plt.close()

plt.imshow(t_30)
plt.savefig("Onda_t30.png")
plt.close()

# Codigo para animar la onda.

pts=300
dx_dy=(30)/float(pts-1) 
lista=Onda(60,Tiempo)[1] 
fig=plt.figure()
Frame=plt.imshow(np.abs(lista[0]), cmap ="flag", extent=(30+dx_dy, 30-dx_dy,30+dx_dy, 30-dx_dy))

def animacion(i):
	Frame.set_array(abs(lista[i]))
	return Frame

ani=animation.FuncAnimation(fig, animacion, np.arange(1, len(lista)), interval=20, blit=False)
