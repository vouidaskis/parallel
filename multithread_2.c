//6007 βουιδασκης χαραλαμπος
#include <stdio.h>
#include "util.h"
#include <pthread.h>
pthread_mutex_t mutex,mute;//create a mutex for synchronization and avoid  race conditions 

int rep,argc,k;

int krata();

void *func(void *param) {//function for threads
int j;
	char *p = (char *) param;
	pthread_mutex_lock (&mutex); 
	init();
	pthread_mutex_unlock (&mutex);//unlock and Continue next
	krata(); 
	pthread_mutex_lock (&mute);
	krata();//for activate unlock
	pthread_mutex_lock (&mute);//wait unlock
	pthread_mutex_unlock (&mute);// unlock for Continuity where not join the function
for(j=0; j<rep; j++){
	pthread_mutex_lock (&mutex);
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
	pthread_mutexattr_init(&attr); 
	pthread_mutex_init(&mutex, &attr);
	pthread_t id[argc];
 	pthread_mutex_init(&mutex, &attr);

	for(i=2; i<argc; i++){//create pthread
	pthread_create(&id[i],NULL , func,(void *) argsv[i]);


}
	for(i=2; i<argc; i++){//wait until finish the thread

	pthread_join(id[i], NULL);
}	pthread_mutex_destroy(&mutex);
}


int krata(){

k--;
if(k<=1){
	 pthread_mutex_unlock (&mute);
}
return k;
}
