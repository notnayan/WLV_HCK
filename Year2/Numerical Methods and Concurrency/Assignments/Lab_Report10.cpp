// gcc labreport9.c -o labreport9 -pthread

 // 1
// #include <stdio.h>
// #include <pthread.h>
// int count = 0;
// pthread_mutex_t mutex;

// void *fun(void *arg)
// {
//     pthread_mutex_lock(&mutex);
//     count++;
//     int i;
//     printf("Thread%d has started\n", count);
//     for (i = 1; i <= 1000000; i++)
//     {
//     }
//     printf("Thread %d has finished\n", count);
//     pthread_mutex_unlock(&mutex);
// }

// void main()
// {
//     pthread_mutex_init(&mutex, NULL);
//     pthread_t thread1, thread2;
//     pthread_create(&thread1, NULL, fun, NULL);
//     pthread_create(&thread2, NULL, fun, NULL);
//     pthread_join(thread1, NULL);
//     pthread_join(thread2, NULL);
//     pthread_mutex_destroy(&mutex);
// }

// 2
//#include <stdio.h>
//#include <pthread.h>
//#include <unistd.h>
//int counter = 0;
//pthread_mutex_t mutex;
//void *threadOne(void *p)
//{
//    pthread_mutex_lock(&mutex);
//    int i;
//    int temp;
//    for (i = 1; i <= 3; i++)
//    {
//        temp = counter;
//        sleep(1);
//        counter = temp + 1;
//    }
//    pthread_mutex_unlock(&mutex);
//}
//void *threadTwo(void *p)
//{
//    pthread_mutex_lock(&mutex);
//    int i;
//    int temp;
//    for (i = 1; i <= 3; i++)
//    {
//        temp = counter;
//        sleep(1);
//        counter = temp - 1;
//    }
//    pthread_mutex_unlock(&mutex);
//}
//void main()
//{
//    pthread_mutex_init(&mutex, NULL);
//    pthread_t thrID1, thrID2;
//    pthread_create(&thrID1, NULL, threadOne, NULL);
//    pthread_create(&thrID2, NULL, threadTwo, NULL);
//
//    pthread_join(thrID1, NULL);
//    pthread_join(thrID2, NULL);
//    printf("counter = %d\n", counter);
//    pthread_mutex_destroy(&mutex);
//}
