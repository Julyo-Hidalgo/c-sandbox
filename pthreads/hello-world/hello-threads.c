#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3

void* print_hello_world(void* tid) {
    int thread_id = *((int*)tid);  // Converta o ponteiro para int e desreferencie
    printf("Hello world!! Eu sou a thread %d!\n", thread_id);
    free(tid);  // Liberar a memória alocada
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int status;

    for (int i = 0; i < NUM_THREADS; i++) {
        printf("Programa principal criando a %d thread!\n", i);

        int *arg = malloc(sizeof(int));  // Aloca memória para o argumento da thread
        if (arg == NULL) {
            perror("malloc");
            exit(1);
        }

        *arg = i;  // Atribua o valor de i ao argumento

        status = pthread_create(&threads[i], NULL, print_hello_world, arg);  // Passa o ponteiro

        if (status != 0) {
            printf("Erro ao criar a thread %d\n", i);
            exit(-1);
        }
    }

    // Espera todas as threads terminarem
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

