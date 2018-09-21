#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#define NUM_THREADS 10

void handle_sig(int sig)
{
    printf("Caught %d signal\n", sig);
}

void *basic(void *ptid)
{
    long tid;
    int i = 0;

    tid = (long)ptid;
    signal(SIGSEGV, handle_sig);
    printf("Hello, I am thread %ld\n", tid);
    sleep(2);

    if (tid == 3) {
        int *ptr = 0;
        int val = *ptr;
        //raise(SIGSEGV);
    }
    printf("Thread %ld is exiting\n", tid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];

    int rc;
    long t;

    for (t=0; t<NUM_THREADS; ++t) {
        printf("Creating thread %ld\n", t);
        rc = pthread_create(&threads[t], NULL, basic, (void*)t);
        if (rc) {
            printf("ERROR in creating thread: %d\n", rc);
            exit(-1);
        }
    }

    while(1) {
        sleep(10);
        printf("Main thread is up %d\n", getpid());
    }

/*
    for (t=0; t<NUM_THREADS; t++) {
        rc = pthread_join(threads[t], NULL);
        if (rc) {
            printf("ERROR while joining the threads: %d\n", rc);
            exit(-1);
        }
        printf("Thread %ld completed\n", t);
    }
*/
    return 0;
}
