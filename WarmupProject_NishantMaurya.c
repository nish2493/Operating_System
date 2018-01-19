#include <pthread.h>			
#include <stdio.h>			
#include <stdlib.h>
#define number_of_threads 5		//Defining the number of threads that need to be created and storing it in number_of_threads

int SharedVariable = 0;			//Global Variable created to change it in threads


//The function to be executed by all threads
void *SimpleThread(void *threadid)												
{
	long tid;																	
	tid = (long)threadid;		//Store the value argument passed to the thread
	int val;																	
	
	//Static variable to see the changes
	val = SharedVariable;		
	
	//Print the shared global variable
	printf("thread #%ld sees value %d\n", tid, val); 
	
	//Increment the global variable
	SharedVariable = val + 1;	
	
	//Exit the thread 
	pthread_exit(NULL);		
}

int main()																		
{
	pthread_t threads[number_of_threads];										
	int ct;			
		
	//Loop to create 5 threads													
	for(long i = 0; i < number_of_threads; i++){	
		printf("Thread %ld\n", i);
		ct = pthread_create(&threads[i], NULL, SimpleThread, (void *)i);		
		if(ct){

			//If Error occurs this gets printed on the screen												
			printf("ERROR; return code from pthread_create() is %d\n", ct);		
			exit(-1);
		}
	}
	pthread_exit(NULL);
}
