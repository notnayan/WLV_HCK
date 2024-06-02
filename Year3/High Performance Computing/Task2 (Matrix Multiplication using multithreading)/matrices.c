/*
Student Name: Nayan Raj Khanal
University ID: 2227486

This C code implements a matrix multiplication program using pthreads (POSIX threads). 
The program reads matrices from an input file, performs matrix multiplication using a specified number of threads, and writes the result to an output file. 
It defines a structure ThreadInfo to hold information about each thread, including the matrices' dimensions and the range of rows it is responsible for. 
Functions for matrix allocation, freeing, reading from a file, and the actual matrix multiplication are implemented. 
The main function reads matrices from the input file, checks for compatibility, initializes threads, assigns work to each thread, waits for thread completion, and writes the result to the output file. 
The program takes command-line arguments for the input file and the number of threads to use. 
Additionally, it handles errors, such as insufficient command-line arguments, file opening failures, and matrix compatibility issues.

1.  Read data from file appropriately
The readMatrix function is responsible for reading matrices from a file. 
It uses dynamic memory allocation with malloc to create the matrices and then reads the matrix elements from the file using fscanf.

2. Using dynamic memory (malloc) for matrix A and matrix B:
The program allocates memory for matrices using the allocateMatrix function, which also utilizes dynamic memory allocation with malloc. 
This ensures that memory is allocated based on the specified number of rows and columns for each matrix.

3.  Creating an algorithm to multiply matrices correctly:
The core matrix multiplication logic is implemented in the multiplyMatrices function. 
Each thread is assigned a specific range of rows to compute, and within this range, it performs the matrix multiplication using nested loops. 
The ThreadInfo structure holds information necessary for each thread to perform its computation.

4. Using multithreading with equal computations:
The program creates a specified number of threads (determined by the command-line argument) in the main function. 
Each thread is assigned a portion of the matrix to compute, ensuring equal distribution of computation. 
The threads run concurrently, improving the overall performance of matrix multiplication.

5. Storing the correct output matrices in the correct format to a file:
The program writes the shape of the resultant matrix to the output file and then writes the calculated matrix. 
The resulting matrices are formatted and written to the file, with spaces between elements and newline characters to separate rows. 
Empty lines are added between matrices in the output file.
*/

// Header files
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Structure containing Thread Information
typedef struct
{
    int threadID;
    int startRow, endRow;
    int rowsMatrixA, colsMatrixA, rowsMatrixB, colsMatrixB;
    double **matrixA;
    double **matrixB;
    double **resultMatrix;
} ThreadInfo;

// Read a matrix from a file and return the matrix
double **readMatrix(FILE *file, int rows, int cols)
{
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (double *)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; j++)
        {
            fscanf(file, "%lf,", &matrix[i][j]);
        }
    }
    return matrix;
}

// Allocate memory for a matrix and return the matrix
double **allocateMatrix(int rows, int cols)
{
    double **matrix = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (double *)malloc(cols * sizeof(double));
    }
    return matrix;
}

// Free the memory allocated for a matrix
void freeMatrix(double **matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to multiply matrices within a specific range assigned to a thread
void *multiplyMatrices(void *arg)
{
    ThreadInfo *info = (ThreadInfo *)arg;
    printf("Thread %d is multiplying matrices of shape (%d, %d) and (%d, %d)\n",
           info->threadID, info->rowsMatrixA, info->colsMatrixA, info->rowsMatrixB, info->colsMatrixB);

    sleep(0.1);

    // Perform matrix multiplication for the assigned rows
    for (int i = info->startRow; i < info->endRow; i++)
    {
        for (int j = 0; j < info->colsMatrixB; j++)
        {
            double sum = 0.0;
            for (int k = 0; k < info->colsMatrixA; k++)
            {
                sum += info->matrixA[i][k] * info->matrixB[k][j];
            }
            info->resultMatrix[i][j] = sum;
        }
    }

    printf("Thread %d completed multiplication.\n", info->threadID);

    pthread_exit(NULL);
}

// Main function that reads matrices from an input file, performs multiplication using threads, and writes the result to an output file
int main(int argc, char *argv[])
{
    // Ensure the correct number of command-line arguments is provided.
    if (argc != 3)
    {
        fprintf(stderr, "ERROR: Please provide arguments as %s <input_file> <number_of_threads>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open the input file for reading.
    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile)
    {
        perror("ERROR: Unable to open the input file!");
        exit(EXIT_FAILURE);
    }

    // Obtain the number of threads from the command line.
    int numThreads = atoi(argv[2]);

    // Open the output file for writing.
    FILE *outputFile = fopen("matrix_multiplication.txt", "w");
    if (!outputFile)
    {
        perror("ERROR: Unable to open the output file!");
        fclose(inputFile);
        exit(EXIT_FAILURE);
    }

    // Initialize variables to track the number of matrices read.
    int matricesRead = 0;
    int rowsMatrixA, colsMatrixA, rowsMatrixB, colsMatrixB;

    // Read matrices from the input file and perform matrix multiplication.
    while (fscanf(inputFile, "%d,%d", &rowsMatrixA, &colsMatrixA) == 2)
    {

        // Read the first matrix from the file.
        double **matrixA = readMatrix(inputFile, rowsMatrixA, colsMatrixA);

        // Read the dimensions of the second matrix.
        fscanf(inputFile, "%d,%d", &rowsMatrixB, &colsMatrixB);

        // Read the second matrix from the file.
        double **matrixB = readMatrix(inputFile, rowsMatrixB, colsMatrixB);

        // Check if matrices can be multiplied.
        if (colsMatrixA != rowsMatrixB)
        {
            fprintf(stderr, "ERROR: Columns of MatrixA do not match rows of MatrixB\n");
            fclose(inputFile);
            fclose(outputFile);
            exit(EXIT_FAILURE);
        }

        // Print the shape of the resultant matrix to the output file.
        fprintf(outputFile, "%d, %d\n", rowsMatrixA, colsMatrixB);

        // Allocate memory for the result matrix.
        double **resultMatrix = allocateMatrix(rowsMatrixA, colsMatrixB);

        // Create an array of threads and ThreadInfo structures.
        pthread_t threads[numThreads];
        ThreadInfo threadInfo[numThreads];

        // Calculate the number of rows each thread will process.
        int rowsPerThread = rowsMatrixA / numThreads;

        // Create threads for matrix multiplication.
        for (int i = 0; i < numThreads; i++)
        {
            // Create ThreadInfo structure for each thread and assign values.
            threadInfo[i] = (ThreadInfo){
                .matrixA = matrixA,
                .matrixB = matrixB,
                .resultMatrix = resultMatrix,
                .rowsMatrixA = rowsMatrixA,
                .colsMatrixA = colsMatrixA,
                .rowsMatrixB = rowsMatrixB,
                .colsMatrixB = colsMatrixB,
                .startRow = i * rowsPerThread,
                .endRow = (i == numThreads - 1) ? rowsMatrixA : (i + 1) * rowsPerThread,
                .threadID = i,
            };

            // Create threads for matrix multiplication.
            pthread_create(&threads[i], NULL, multiplyMatrices, (void *)&threadInfo[i]);
        }

        // Wait for all threads to complete.
        for (int i = 0; i < numThreads; i++)
        {
            pthread_join(threads[i], NULL);
        }

        // Save the result to the output file.
        for (int i = 0; i < rowsMatrixA; i++)
        {
            for (int j = 0; j < colsMatrixB; j++)
            {
                fprintf(outputFile, "%.6f", resultMatrix[i][j]);
                if (j < colsMatrixB - 1)
                {
                    fprintf(outputFile, " ");
                }
            }
            fprintf(outputFile, "\n");
        }

        // Free allocated memory.
        freeMatrix(matrixA, rowsMatrixA);
        freeMatrix(matrixB, rowsMatrixB);
        freeMatrix(resultMatrix, rowsMatrixA);

        // Add empty lines between matrices in the output file.
        fprintf(outputFile, "\n\n");
        matricesRead++;
    }

    // Close files.
    fclose(inputFile);
    fclose(outputFile);

    // Check if there are at least two matrices in the input file.
    if (matricesRead < 2)
    {
        fprintf(stderr, "ERROR: Insufficient number of matrices in the input file.\n");
        exit(EXIT_FAILURE);
    }

    // Return success status.
    return 0;
}
