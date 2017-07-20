import numpy as np
import matplotlib.pyplot as plt

pts=30
alfa=0.5
dx=0.3
c=1.
dt=(alfa**(1./2.)*(dx/c))
r=c*(dt/dx)
#r1=(c**2)((dt**2)/(dx**2))

u_inicial=np.zeros((pts,pts))
u_inicial[(pts/3)-1, (pts/2)-1]=-0.5

u_inicial[:,0]=0
u_inicial[0,:]=0
u_inicial[:,-1]=0
u_inicial[-1,:]=0
u_inicial[((pts*2)/3)-1, :((pts/2)-pts/30)]=0
u_inicial[((pts*2)/3)-1 ,((pts/2)+(pts/30)+1):]=0


u_futuro=np.copy(u_inicial)
print(r**2)
#print(r1)



for i in range(1,pts-1):
	for j in range(1,pts-1):
		u_futuro[i,j]=(u_inicial[i,j]+(r**2/2.0)*(u_inicial[i+1,j]-2.0*u_inicial[i,j]+u_inicial[i-1,j]))+(u_inicial[i,j]+(r**2/2.0)*(u_inicial[i,j+1]-2.0*u_inicial[i,j]+u_inicial[i,j-1]))
		u_futuro[:,0]=0
		u_futuro[0,:]=0
		u_futuro[:,-1]=0
		u_futuro[-1,:]=0
		u_futuro[((pts*2)/3)-1, :((pts/2)-pts/30)]=0
		u_futuro[((pts*2)/3)-1 ,((pts/2)+(pts/30)+1):]=0

u_pasado=np.copy(u_inicial)
u_presente=np.copy(u_futuro)

#Siguientes iteraciones

iteraciones= 3/dt
#print(int(iteraciones))
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



plt.imshow(u_presente)
plt.show()