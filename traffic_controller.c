#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t redLight;
sem_t yellowLight;
sem_t greenLight;

void* red(void* arg) {
    while (1) {
        sem_wait(&redLight);
        printf("RED light ON\n");
        sleep(3);
        printf("RED light OFF\n");
        sem_post(&greenLight);
    }
}

void* green(void* arg) {
    while (1) {
        sem_wait(&greenLight);
        printf("GREEN light ON\n");
        sleep(3);
        printf("GREEN light OFF\n");
        sem_post(&yellowLight);
    }
}

void* yellow(void* arg) {
    while (1) {
        sem_wait(&yellowLight);
        printf("YELLOW light ON\n");
        sleep(2);
        printf("YELLOW light OFF\n");
        sem_post(&redLight);
    }
}

int main() {
    pthread_t redThread, yellowThread, greenThread;

    sem_init(&redLight, 0, 1);
    sem_init(&yellowLight, 0, 0);
    sem_init(&greenLight, 0, 0);

    pthread_create(&redThread, NULL, red, NULL);
    pthread_create(&yellowThread, NULL, yellow, NULL);
    pthread_create(&greenThread, NULL, green, NULL);

    pthread_join(redThread, NULL);
    pthread_join(yellowThread, NULL);
    pthread_join(greenThread, NULL);

    sem_destroy(&redLight);
    sem_destroy(&yellowLight);
    sem_destroy(&greenLight);

    return 0;
}
