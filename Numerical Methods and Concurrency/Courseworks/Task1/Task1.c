#include <stdio.h>

int main() {
	
// Variable declaration
int n = 0;
int i;
double A, B;
double xinput, youtput;
double x[1000], y[1000];
double sumX = 0, sumY = 0, sumXsq = 0, sumYsq = 0, sumXY = 0;

// Declaring file pointers and opening each dataset file in read mode
FILE *fptr[4];                          
fptr[0] = fopen("datasetLR1.txt", "r"); 
fptr[1] = fopen("datasetLR2.txt", "r"); 
fptr[2] = fopen("datasetLR3.txt", "r"); 
fptr[3] = fopen("datasetLR4.txt", "r"); 

// Loop 4 times to read the data from all 4 files
for (i = 0; i < 4; i++) {
    // Using fscanf to access dataset values and store in the x and y arrays until the end of file
    while (fscanf(fptr[i], "%lf,%lf", &x[n], &y[n]) != EOF) {
        n++; 
    }
    // Close each file pointer after reading the data
    fclose(fptr[i]); 
}

// Calculate required values to get A and B
for (i = 0; i < n; i++) {
    sumX += x[i];
    sumY += y[i];
    sumXsq += x[i] * x[i];
    sumYsq += y[i] * y[i];
    sumXY += x[i] * y[i];
}

// Print output
printf("Total sum of X: %.4lf \n", sumX);
printf("Total sum of Y: %.4lf \n", sumY);
printf("Total sum of Xsquare: %.4lf \n", sumXsq);
printf("Total sum of Ysquare: %.4lf \n", sumYsq);
printf("Total sum of X * Y: %.4lf \n", sumXY);

// Calculate line-intercept (A) and slope (B)
A = ((sumY * sumXsq) - (sumX * sumXY)) / ((n * sumXsq) - (sumX * sumX)); 
B = ((n * sumXY) - (sumX * sumY)) / ((n * sumXsq) - (sumX * sumX));     

// Print the line-intercept and slope
printf("The line-intercept (A): %.4lf \n", A);
printf("The slope (B): %.4lf \n", B);

printf("The equation of the line is: y = %.4lf * x + %.4lf \n", B, A);

// Get input value for x from the user
printf("\t Enter the value of x: ");
scanf("%lf", &xinput);

// Print the user input
printf("\t Input value of X by the user: %lf \n", xinput);

// Predict output with input
youtput = B * xinput + A;

// Print predicted value of Y
printf("\n\t Predicted value of Y is : %lf", youtput);

return 0;
}
