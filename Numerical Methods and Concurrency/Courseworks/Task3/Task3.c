#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

clock_t start, end;
double cpu_time;
// numbers_array is the variable to store prime number
int *numbers_array;
// primecount counts no of prime numbers
int primecount = 0;
FILE *fptr;

// mtx variable to lock critical section
pthread_mutex_t mtx;

// structure used to pass starting and ending index to thread
struct calculate
{
    int start;
    int finish;
};
 
// Returns 1 if number is prime
int checkPrime(int n, int i)
{
    if (n <= 2)
    {
        return (n == 2) ? 1 : 0;
    }
    if (n % i == 0)
    {
        return 0;
    }
    if (i * i > n)
    {
        return 1;
    }
    return checkPrime(n, i + 1);
}

// Check if the number in array is prime or not
void *isPrime(void *ptr)
{
    struct calculate *arg = ptr;
    int st = arg->start, fi = arg->finish;
    int i, j;
    for (i = st; i <= fi; i++)
    {
        int num = *(numbers_array + i);
        if (checkPrime(num, 2) == 1)
        {
            pthread_mutex_lock(&mtx);
            primecount++;
            fprintf(fptr, "%d. %d\n", primecount, num);
            pthread_mutex_unlock(&mtx);
        }
    }
}

void main()
{
 	// Declare variables
    int i, n = 0, j = 0, nof = 3;
    FILE *fptr;
    char filename[15], chr;
    int not;
 
    // Find total numbers in individual files
    for (i = 1; i <= nof; i++)
    {
        sprintf(filename, "PrimeData%d.txt", i);
        fptr = fopen(filename, "r");
        chr = getc(fptr);
        while (chr != EOF)
        {
            if (chr == '\n')
            {
                if (chr != ' ')
                {
                    n++;
                }
            }
            chr = getc(fptr);
        }
        fclose(fptr);
    }
 
    printf("Find prime numbers from total (%d) numbers to check. Use multithreading to make process faster!", n);
    printf("\n\nNumber of threads: ");
    scanf("%d", &not);
    struct calculate divider[not];
 
    // Using dynamic memory allocation to store number in array
    numbers_array = (int *)malloc(n * sizeof(int));
    for (i = 1; i <= nof; i++)
    {
        sprintf(filename, "PrimeData%d.txt", i);
        fptr = fopen(filename, "r");
        
        // Loop until the end of file
        while (!feof(fptr))
        {   
            // Use scanf function to add number in array
            fscanf(fptr, "%d\n", (numbers_array + j));
            j++;
        }
        fclose(fptr);
    }
 
    // Slicing the threads to make process faster
    int slice[not];
    for (i = 0; i < not; i++)
    {
        slice[i] = n / not;
    }
    int reminder = n % not;
    for (i = 0; i < reminder; i++)
    {
        slice[i]++;
    }
    int startList[not], endList[not];
    for (i = 0; i < not; i++)
    {
        if (i == 0)
        {
            startList[i] = 0;
        }
        else
        {
            startList[i] = endList[i - 1] + 1;
        }
        endList[i] = startList[i] + slice[i] - 1;
    }
 
    // Opening file in write mode 
    fptr = fopen("PrimeNumbers.txt", "w");

    // Initialize mutex
    start = clock();
    pthread_mutex_init(&mtx, NULL);
 
    // Adding start index and end index to the structure and also creating threads to check all numbers from start to end
    pthread_t threads[not];
    for (i = 0; i < not; i++)
    {
        divider[i].start = startList[i];
        divider[i].finish = endList[i];
        pthread_create(&threads[i], NULL, isPrime, &divider[i]);
    }
    
    // Joining the threads
    for (i = 0; i < not; i++)
    {
        pthread_join(threads[i], NULL);
    }
    
    // Destroying the mutex
    pthread_mutex_destroy(&mtx);
    end = clock();
 
 	// Find the total time required for computation
    cpu_time = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Total Time Taken = %.2lf seconds", cpu_time);
 
    // Print the total prime numbers found
    printf("\nTotal Prime Count: %d\n", primecount);
    fprintf(fptr, "\n\nThere are total of %d prime numbers.", primecount);
    
    // Free pointer
    free(numbers_array);

	// Print output
    printf("\nProcess complete!!\n\t\"PrimeNumbers.txt\" file has been created.\n\tCheck the file to see all prime numbers.");
    fclose(fptr);
}
 
