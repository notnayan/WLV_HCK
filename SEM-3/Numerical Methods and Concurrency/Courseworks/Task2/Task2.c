#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mtx; 
double sum = 0;   
long long n;
int i;    

struct iterables
{
    long long startPoint, endPoint; // Variables to store the starting point and ending point of the iteration for each thread
};

double powerUp(long long b) 
{
    // Check if the input b is equal to 0
    if (b == 0) 
    {
        // If it is, return 1
        return 1;
    }
    // If b is not equal to 0, return -1 multiplied by the result of calling powerUp with b-1 as the input
    return -1 * powerUp(b - 1); 
}

void *findSum(void *arg) 
{                        
    struct iterables *s = (struct iterables *)arg;       
    long long startPoint = s->startPoint; // starting point 
    long long endPoint = s->endPoint;    // Ending point
    
	// Loop from starting point to the ending point
    for (n = startPoint; n <= endPoint; n++) 
    {
        pthread_mutex_lock(&mtx);           
        sum += (powerUp(n)) / ((2 * n) + 1); 
        pthread_mutex_unlock(&mtx);         
    }
    pthread_exit(0); 

} 

// Slice thread
struct iterables *sliceData(int noT, long long iterations) 
{
    int slicedList[noT];             
    int remainder = iterations % noT; 

    for (i = 0; i < noT; i++) 
    {
        //slice data equally
        slicedList[i] = iterations / noT; 
    }

    for (i = 0; i < remainder; i++) 
    {
        slicedList[i] = slicedList[i] + 1; 
    }

    int startingPointList[noT]; // Starting point 
    int endingPointList[noT];   // Ending point 

    for (i = 0; i < noT; i++) 
    {
        if (i == 0) 
        {
                //first iteration as starting point
            startingPointList[i] = 0; 
        }
        else 
        {
            startingPointList[i] = endingPointList[i - 1] + 1;
        }
        //(sliced data) added to its starting point is its ending point
        endingPointList[i] = startingPointList[i] + slicedList[i] - 1; 
    }

    // Starting and ending point memory according to our number of threads
    struct iterables *structure = malloc(noT * sizeof(struct iterables)); 

    for (i = 0; i < noT; i++) 
    {
        structure[i].startPoint = startingPointList[i]; 
        structure[i].endPoint = endingPointList[i];  
    }
    
    return structure; 

} 

void main() 
{
    long long iterations;
    int noT;

    // Ask for number of iterations
    printf("Number of iterations: ");
    scanf("%lld", &iterations);

    // Ask for number of threads
    printf("Number of threads: ");
    scanf("%d", &noT);

    struct iterables *structure = sliceData(noT, iterations); 

    pthread_t thread[noT]; 

    // Threads
    for (i = 0; i < noT; i++)
    {
        pthread_create(&thread[i], NULL, findSum, &structure[i]);
    }

    for (i = 0; i < noT; i++)
    {
        pthread_join(thread[i], NULL);
    }
    
    // Destroying the mutex lock after every threads ran completely
    pthread_mutex_destroy(&mtx); 
    
    printf("\nValue of Pi according to Leibniz formula is %.3lf", 4 * sum);
} 
