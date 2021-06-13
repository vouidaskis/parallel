//6007 βουιδασκης χαραλαμπος
#include <stdio.h>
#include "util.h"
#include <pthread.h>//sumperilambanoume th bibliothhkh gia pthread
pthread_mutex_t mutex,mute;//dhmiourgia enos mutex gia sugxronismo kai ara apofugh race conditions kai sugkekrimena gia amoibaio apokleismo

int rep,argc,k;

int krata();

void *func(void *param) {//sunarthsh gia to nhmaτα
int j;
	char *p = (char *) param;
	pthread_mutex_lock (&mutex); //mpainei athe argument diaforetika mono toy logo toy lock
	init();
	pthread_mutex_unlock (&mutex);//hekleidwnei kai mpainei to epomeno
	krata();//exoyme thn synarthsh poy miwnei kathe fora miwn ena 
	pthread_mutex_lock (&mute);//exoyme to lock poy den to afhnei na perasei mexrh na vrei unlock
	 krata();//gia na energopoihsei to unlock
	 pthread_mutex_lock (&mute);//perimenei to unlock
	 pthread_mutex_unlock (&mute);//kanei unlock gia thn synexeia pou den sumrtasxei h synarthsh krata
for(j=0; j<rep; j++){
	pthread_mutex_lock (&mutex);//kanei oti kai prin
	display(p);
	pthread_mutex_unlock (&mutex);
}

	return NULL;
}

int main(int argc, char **argsv) {
int i;
k=argc;
rep=atoi(argsv[1]);
	int status;


	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr); //arxikopoihsh antikeimenwn idiothtwn mutex
	pthread_mutex_init(&mutex, &attr);////arxhkopoiei to kleidh me pinakaarxikopoihsh tou mutex
	pthread_t id[argc];
 	pthread_mutex_init(&mutex, &attr);

	for(i=2; i<argc; i++){//dhmiourgia pthread gia to prwto nhma, dhladh gia ths sunarthsh
	pthread_create(&id[i],NULL , func,(void *) argsv[i]);


}
	for(i=2; i<argc; i++){//perimenei na teleiwsoun ta nimata

	pthread_join(id[i], NULL);
}	pthread_mutex_destroy(&mutex);
}


int krata(){//kathe fora pou mpainei shmainei pws ektelesthike mia fora to init an kanri tis aferseis oses fores mpain kia paei <=1 tote 
//snexizrei gia thn display
k--;
if(k<=1){
	 pthread_mutex_unlock (&mute);
}
return k;
}
