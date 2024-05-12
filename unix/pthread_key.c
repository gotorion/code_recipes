#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_key_t key;
struct test_struct
{
    int i;
    float k;
};

void *first_thread_func(void *arg)
{
    struct test_struct struct_data;
    printf("address of struct = %p\n", &struct_data);
    struct_data.i = 1;
    struct_data.k = 2.31f;
    pthread_setspecific(key, &struct_data);

    struct test_struct *ptr = (struct test_struct *)pthread_getspecific(key);
    printf("first thread local varible address = %p\n", ptr);
    printf("first thread local varible, i = %d, k = %.2f\n", ptr->i, ptr->k);
    printf("-----------------------------------------\n");
}

void *second_thread_func(void *arg)
{
    int num = 10;
    pthread_setspecific(key, &num);

    int *ptr = (int *)(pthread_getspecific(key));
    printf("second thread local varible address = %p\n", ptr);
    printf("second thread local varible, str = %d\n", ptr);
    printf("-----------------------------------------\n");
}

int main(void)
{
    pthread_t first_thread;
    pthread_t second_thread;

    pthread_key_create(&key, NULL);
    pthread_create(&first_thread, NULL, first_thread_func, NULL);
    pthread_create(&second_thread, NULL, second_thread_func, NULL);

    pthread_join(first_thread, NULL);
    pthread_join(second_thread, NULL);

    pthread_key_delete(key);
    return 0;
}
