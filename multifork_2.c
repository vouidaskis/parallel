//6007 βουιδασκης χαραλαμπος
#include <stdio.h>
#include "util.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>



int main(int argc, char **argsv){

struct sembuf up= {0, 1, 0};//edw exoyme up
struct sembuf down = {0, -1, 0};// edw exoyme down
int i,j,rep,status,my_sem,gy,ep,per;
rep=atoi(argsv[1]);//gia na apothikeysoyme thn timh se intiger pou dinei o xrhsths
my_sem = semget(IPC_PRIVATE, 1, 0600);//dimioyrgia enos shmaforoys
gy=semget(IPC_PRIVATE, 1, 0600);
semop(my_sem, &up, 1);
semop(gy, &up, 1);
per = semget(IPC_PRIVATE, 1, 0600);
for(i=2; i<argc; i++) {//aujanoyme to gy ases epanalhpseis einai ta argoument
	semop(gy, &up, 1);
	ep = semctl(gy, 0, GETVAL);
}
for(i=2; i<argc; i++) {
	if(fork()!=0){

	}
	else{
		 ep = semctl(gy, 0, GETVAL);//leei posa up exei o gy
		
			semop(my_sem, &down, 1);//vazei mia mia tis entoles tis entoles sto init gia na tis dwsei omorfa kai to kleidwnei
			init();
			semop(my_sem, &up, 1);//edw to 3eklidwnei

			semop(gy, &down, 1);//katevazei to gy -1
			ep = semctl(gy, 0, GETVAL);//to emfonizei poso einai 
		if(ep==2){//an einai ep==2 tote kanei yp thn per
			 semop(per, &up, 1);
		}

		 semop(per, &down, 1);//perimenei mexrh na ginnei up h per
		for(j=0; j<rep; j++){//kanei oti to multiproc_1 h sunexia

			semop(my_sem, &down, 1);
			display(argsv[i]);
			semop(my_sem, &up, 1);
		}
		semop(per, &up, 1);

	exit(0);
	}
}

for(i=2; i<argc; i++){
wait(&status);
}
semctl(per, 0, IPC_RMID);//kleinw tis shmaioforous
semctl(gy, 0, IPC_RMID);
semctl(my_sem, 0, IPC_RMID);
  return 0;
}
