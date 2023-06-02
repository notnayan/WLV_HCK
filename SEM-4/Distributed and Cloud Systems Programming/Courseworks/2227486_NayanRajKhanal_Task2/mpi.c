#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int size, rank;
    int *numbers;
    int total, average, largestPositive, largestNegative;

    MPI_Init(NULL, NULL);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (size <= 2 || size >= 10)
    {
        printf("This program must run on minimum of 2 processes and a maximum of 10 processes.\n");
        exit(1);
        MPI_Finalize();
    }

    if (rank == 0)
    {
        // File handling to open input.txt
        FILE *fp;
        fp = fopen("input.txt", "r");
        if (fp == NULL)
        {
            printf("Error opening file\n");
            MPI_Finalize();
            exit(1);
        }

        // Dynamically allocate memory for numbers array based on the count of numbers in the file
        int count = 0;
        int number;
        while (fscanf(fp, "%d", &number) == 1)
        {
            numbers = (int *)realloc(numbers, (count + 1) * sizeof(int));
            numbers[count] = number;
            count++;
        }

        // Check if realloc was successful
        if (numbers == NULL)
        {
            fprintf(stderr, "Error: Could not allocate memory for numbers array\n");
            exit(1);
        }

        // Close the file
        fclose(fp);

        // Divide the numbers equally between all the processes
        int numbersPerProcess = count / (size - 1);
        int remainder = count % (size - 1);
        int start = 0;
        int end = numbersPerProcess;

        for (int i = 1; i < size; i++)
        {
            if (remainder > 0)
            {
                end++;
                remainder--;
            }
            MPI_Send(&numbers[start], end - start, MPI_INT, i, 0, MPI_COMM_WORLD);
            start = end;
            end += numbersPerProcess;
        }

        // Receive the calculated values from all the processes
        int values[4];
        for (int i = 1; i < size; i++)
        {
            MPI_Recv(values, 4, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            total += values[0];
            largestPositive = values[2] > largestPositive ? values[2] : largestPositive;
            largestNegative = values[3] < largestNegative ? values[3] : largestNegative;
        }

        average = total / count;
        printf("Total: %d\n", total);
        printf("Average: %d\n", average);
        printf("Largest Positive Number: %d\n", largestPositive);
        printf("Largest Negative Number: %d\n", largestNegative);
    }
    else
    {
        // Receive the numbers from the Rank 0 process
        MPI_Status status;
        MPI_Probe(0, 0, MPI_COMM_WORLD, &status);
        int count;
        MPI_Get_count(&status, MPI_INT, &count);
        numbers = (int *)malloc(count * sizeof(int));
        MPI_Recv(numbers, count, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

        // Calculate the total, average, largest positive number and the largest negative number
        total = 0;
        largestPositive = 0;
        largestNegative = 0;
        for (int i = 0; i < count; i++)
        {
            total += numbers[i];
            if (numbers[i] > largestPositive)
                largestPositive = numbers[i];
            if (numbers[i] < largestNegative)
                largestNegative = numbers[i];
        }
        average = total / count;

        // Send the calculated values back to the Rank 0 process
        int values[4] = {total, average, largestPositive, largestNegative};
        MPI_Send(values, 4, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
