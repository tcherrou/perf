#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int counter = 0;


void *thread_fun(void *DURATION) {
    time_t start_time;
    time_t current_time;
    time(&start_time);
    time(&current_time); 
    while(!(current_time - start_time > *(int *)DURATION)) {
    counter++; 
    time(&current_time);
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    time_t start_time;
    time_t end_time;
    time(&start_time);
    int NB_THREADS;
    int DURATION;
    void* duration_ptr;
    NB_THREADS = atoi(argv[1]);
    DURATION   = atoi(argv[2]);
    duration_ptr = &DURATION;
    pthread_t threads[NB_THREADS]; 
    for(int i = 0; i<NB_THREADS; i++) {
     pthread_t thread;
     pthread_create(&thread,NULL,thread_fun, duration_ptr);
     threads[i] = thread;
    }

    for(int i = 0; i<NB_THREADS; i++) {
      pthread_join(threads[i],NULL);
    }

    time(&end_time);

    printf("%d",counter);

    
    

}
