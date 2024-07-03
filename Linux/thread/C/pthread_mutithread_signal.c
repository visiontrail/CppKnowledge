#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

// gcc -pthread -o condition_example pthread_mutithread_signal.c

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int ready = 0;

void* thread_func(void* arg) {
    int id = *(int*)arg;
    pthread_mutex_lock(&lock);

    while (!ready) {
        printf("Thread %d waiting...\n", id);
        pthread_cond_wait(&cond, &lock); // wait will be release the mutex lock
    }

    printf("Thread %d awakened\n", id);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {1, 2, 3};

    for (int i = 0; i < 3; ++i) {
        pthread_create(&threads[i], NULL, thread_func, &thread_ids[i]);
    }

    // simulate some working process...
    sleep(1);

    pthread_mutex_lock(&lock);
    ready = 1;

    // awake all thread
    // pthread_cond_broadcast(&cond); 
    // or ....
    // awake one of these three thread (beacuse of pthread_join, The program never exit)
    pthread_cond_signal(&cond); 

    pthread_mutex_unlock(&lock);

    for (int i = 0; i < 3; ++i) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}