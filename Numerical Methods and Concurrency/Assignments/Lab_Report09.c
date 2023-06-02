// gcc labreport9.c -o thread -pthread

// 1
// #include <pthread.h>
// #include <stdio.h>

// void *threadOne(void *p)
// {
// 	int i;
//     for (i = 1; i <= 500; i++)
//         printf("%d\n", i);
// }

// void *threadTwo(void *p)
// {
// 	int i;
//     for (i = 501; i <= 1000; i++)
//         printf("%d\n", i);
// }
// void main()
// {
//     pthread_t thrID1, thrID2;
//     pthread_create(&thrID1, NULL, threadOne, NULL);
//     pthread_create(&thrID2, NULL, threadTwo, NULL);
//     pthread_join(thrID1, NULL);
//     pthread_join(thrID2, NULL);
// }

// 2
//#include <stdio.h>
//#include <pthread.h>
//
//void *threadOne(void *p)
//{
//    int i, c;
//    int nstart = 1, nfinish = 250;
//    printf("Prime numbers between %d and %d are :\n", nstart, nfinish);
//    for (i = nstart; i <= nfinish; i++)
//    {
//        for (c = 2; c <= i - 1; c++)
//        {
//            if (i % c == 0)
//                break;
//        }
//        if (c == i)
//            printf("%d\n", i);
//    }
//    return 0;
//}
//
//void *threadTwo(void *p)
//{
//    int i, c;
//    int nstart = 251, nfinish = 500;
//    for (i = nstart; i <= nfinish; i++)
//    {
//        for (c = 2; c <= i - 1; c++)
//        {
//            if (i % c == 0)
//                break;
//        }
//        if (c == i)
//            printf("%d\n", i);
//    }
//    return 0;
//}
//
//void main()
//{
//    pthread_t thrID1, thrID2;
//    pthread_create(&thrID1, NULL, threadOne, NULL);
//    pthread_create(&thrID2, NULL, threadTwo, NULL);
//    pthread_join(thrID1, NULL);
//    pthread_join(thrID2, NULL);
//}

// 3
//#include <pthread.h>
//#include <stdio.h>
//
//void *threadOne(void *p)
//{
//    int i;
//    for (i = 1; i <= 200; i++)
//        printf("%d\n", i);
//}
//void *threadTwo(void *p)
//{
//    int i;
//    for (i = 201; i <= 400; i++)
//        printf("%d\n", i);
//}
//void *threadThree(void *p)
//{
//    int i;
//    for (i = 401; i <= 600; i++)
//        printf("%d\n", i);
//}
//void *threadFour(void *p)
//{
//    int i;
//    for (i = 601; i <= 800; i++)
//        printf("%d\n", i);
//}
//void *threadFive(void *p)
//{
//    int i;
//    for (i = 801; i <= 1000; i++)
//        printf("%d\n", i);
//}
//
//void main()
//{
//    pthread_t thrID1, thrID2, thrID3, thrID4, thrID5;
//    pthread_create(&thrID1, NULL, threadOne, NULL);
//    pthread_create(&thrID2, NULL, threadTwo, NULL);
//    pthread_create(&thrID3, NULL, threadThree, NULL);
//    pthread_create(&thrID4, NULL, threadFour, NULL);
//    pthread_create(&thrID5, NULL, threadFive, NULL);
//    pthread_join(thrID1, NULL);
//    pthread_join(thrID2, NULL);
//    pthread_join(thrID3, NULL);
//    pthread_join(thrID4, NULL);
//    pthread_join(thrID5, NULL);
//}

// 4
//#include <stdio.h>
//#include <pthread.h>
//#include <stdlib.h>
//
//int diff, start = 1, finish;
//
//void *displayNumber(void *p)
//{
//    for (int i = start; i <= finish; i++)
//    {
//        printf("%d\n", i);
//    }
//    start += diff;
//    finish += diff;
//}
//
//int main()
//{
//    pthread_t *thrID;
//    int num, y = 1000;
//    printf("How many threads do you want? ");
//    scanf("%d", &num);
//
//    if (y % num == 0)
//    {
//        thrID = (pthread_t *)malloc(num * sizeof(pthread_t));
//        diff = y / num;
//        finish = diff;
//        for (int i = 0; i < num; i++)
//        {
//            pthread_create(&thrID[i], NULL, displayNumber, NULL);
//        }
//        for (int i = 0; i < num; i++)
//        {
//            pthread_join(thrID[i], NULL);
//        }
//        free(thrID);
//    }
//    else
//    {
//        printf("The thread cannot be created.\n");
//    }
//    return 0;
//}

// 5
//#include <stdio.h>
//#include <pthread.h>
//#include <stdlib.h>
//
//int diff, start = 1, finish;
//
//void *displayOddNumber(void *p)
//{
//    for (int i = start; i <= finish; i++)
//    {
//        if (i % 2 == 1)
//            printf("%d\n", i);
//    }
//    start += diff;
//    finish += diff;
//}
//
//int main()
//{
//    pthread_t *thrID;
//    int num, y = 1000;
//    printf("How many threads do you want? ");
//    scanf("%d", &num);
//
//    if (y % num == 0)
//    {
//        thrID = (pthread_t *)malloc(num * sizeof(pthread_t));
//        diff = y / num;
//        finish = diff;
//        for (int i = 0; i < num; i++)
//        {
//            pthread_create(&thrID[i], NULL, displayOddNumber, NULL);
//        }
//        for (int i = 0; i < num; i++)
//        {
//            pthread_join(thrID[i], NULL);
//        }
//        free(thrID);
//    }
//    else
//    {
//        printf("The thread cannot be created.\n");
//    }
//    return 0;
//}

// 6
//#include <stdio.h>
//#include <pthread.h>
//#include <stdlib.h>
//
//int diff, start = 1, finish;
//int *arr, e, found = 0;
//
//void *searchElement(void *p);
//void take_input(int **arr, int *arr_size);
//
//int main()
//{
//    int arr_size;
//    take_input(&arr, &arr_size);
//
//    printf("Which element do you want to search? ");
//    scanf("%d", &e);
//
//    pthread_t *thrID;
//    int num;
//    printf("How many threads do you want? ");
//    scanf("%d", &num);
//
//    if (arr_size % num == 0)
//    {
//        thrID = (pthread_t *)malloc(num * sizeof(pthread_t));
//        diff = arr_size / num;
//        finish = diff;
//        for (int i = 0; i < num; i++)
//            pthread_create(&thrID[i], NULL, searchElement, NULL);
//        for (int i = 0; i < num; i++)
//            pthread_join(thrID[i], NULL);
//        if (!found)
//            printf("Element not found.\n");
//        free(thrID);
//    }
//    else
//    {
//        printf("The thread cannot be created.\n");
//    }
//    return 0;
//}
//
//void take_input(int **arr, int *arr_size)
//{
//    int i;
//    printf("Enter a number: ");
//    scanf("%d", arr_size);
//
//    *arr = (int *)malloc(*arr_size * sizeof(int));
//
//    for (i = 0; i < *arr_size; i++)
//        (*arr)[i] = i + 1;
//}
//
//void *searchElement(void *p)
//{
//    for (int i = start; i <= finish; i++)
//    {
//        if (arr[i - 1] == e)
//        {
//            printf("Element found at index %d.\n", i - 1);
//            found = 1;
//        }
//    }
//    start += diff;
//    finish += diff;
//}
