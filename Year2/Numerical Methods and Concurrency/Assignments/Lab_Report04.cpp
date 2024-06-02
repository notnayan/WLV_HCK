//01

//#include <stdio.h>
//
//int main()
//{
//    // Declare a variable to store the size of the array
//    int size;
//
//    // Prompt the user to enter the size of the array
//    printf("Enter the size of the array: ");
//
//    // Read the user's input and store it in the size variable
//    scanf("%d", &size);
//
//    // Declare an array of integers
//    int array[size];
//
//    // Read the elements of the array from the user
//    printf("Enter the elements of the array!\n");
//    for (int i = 0; i < size; i++)
//    {
//    	printf("Enter Element %d: ", i+1);
//        scanf("%d", &array[i]);
//    }
//
//    // Declare a pointer to an integer and initialize it to the address of the first element of the array
//    int *ptr = array;
//
//    // Declare a variable to store the sum
//    int sum = 0;
//
//    // Loop through the array, incrementing the pointer to point to the next element on each iteration
//    for (int i = 0; i < size; i++)
//    {
//        // Add the value pointed to by the pointer to the sum
//        sum += *ptr;
//
//        // Increment the pointer to point to the next element
//        ptr++;
//    }
//
//    // Print the sum
//    printf("The sum of all elements in the array is %d\n", sum);
//
//    return 0;
//}

//02

//#include <stdio.h>
//
//int main()
//{
//	//fflush(stdin);
//    // Declare a variable to store the size of the array
//    int size;
//
//    // Prompt the user to enter the size of the array
//    printf("Enter the size of the array: ");
//
//    // Read the user's input and store it in the size variable
//    scanf("%d", &size);
//
//    // Declare an array of integers
//    int array[size];
//    int *ptr = array;
//
//    // Read the elements of the array from the user
//    printf("Enter the elements of the array!\n");
//    										
//    for (int i = 0; i < size; i++, ptr++)
//    {
//    	printf("Enter Element %d: ", i+1);
//        scanf("%d", &array[i]);
//        printf("%u", ptr);
//    }
//    printf("\n");
//    printf("%u", ptr);
//    
//
//	//Prompt the user to enter the element to search for
//    int element;
//    printf("Enter the element to search for: ");
//    scanf("%d", &element);
//
//    // Declare a pointer to an integer and initialize it to the address of the first element of the array
//    int *ptr = array;
//
//    // Declare a variable to store the index of the element, and initialize it to -1
//    int index = -1;
//
//    // Loop through the array, incrementing the ptr pointer to point to the next element on each iteration
//    for (int i = 0; i < size; i++)
//    {
//        // Check if the value pointed to by the ptr pointer is equal to the element to search for
//        if (*ptr == element) 
//        {
//            // If it is, store the current index in the index variable and break out of the loop
//            index = i;
//            break;
//        }
//
//        // Increment the ptr pointer to point to the next element
//        ptr++;
//    }
//
//    // Check if the element was found in the array
//    if (index != -1)
//    {
//        // If it was, print the index at which it was found
//        printf("The element was found at index %d\n", index);
//    }
//    else
//    {
//        // If it wasn't, print a message indicating that the element was not found
//        printf("The element was not found in the array\n");
//    }
//
//    return 0;
//}

//03

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//  int *int_ptr= (int *) malloc(sizeof(int));
//  char *char_ptr= (char *) malloc(sizeof(char));
//  float *float_ptr= (float *) malloc(sizeof(float));
//
//  // Take user input for the values
//  printf("Enter an integer: ");
//  scanf("%d", int_ptr);
//  printf("Enter a character: ");
//  scanf(" %c", char_ptr);
//  printf("Enter a float: ");
//  scanf("%f", float_ptr);
//
//  // Print the values
//  printf("Integer value: %d\n", *int_ptr);
//  printf("Character value: %c\n", *char_ptr);
//  printf("Float value: %.2f\n", *float_ptr);
//
//  // Free the allocated memory
//  free(int_ptr);
//  free(char_ptr);
//  free(float_ptr);
//
//  return 0;
//}


//04

#include <stdio.h>
#include <stdlib.h>

int main() {
  int size;
  int *array= (int *) malloc(size * sizeof(int));
  int max;

  // Get the size of the array from the user
  printf("Enter the size of the array: ");
  scanf("%d", &size);

  // Get the values for the array from the user
  printf("Enter the elements of the array!\n");
    for (int i = 0; i < size; i++)
    {
    	printf("Enter Element %d: ", i+1);
        scanf("%d", &array[i]);
    }

  // Find the maximum value in the array
  max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max) {
      max = array[i];
    }
  }

  printf("The maximum value in the array is %d\n", max);

  // Free the allocated memory
  free(array);

  return 0;
}

//05

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//  int size;
//  int *array1= (int *) malloc(size * sizeof(int));
//  int *array2= (int *) malloc(size * sizeof(int));
//  int *array3= (int *) malloc(size * sizeof(int));
//  // Get the size of the arrays from the user
//  printf("Enter the size of the arrays: ");
//  scanf("%d", &size);
//  // Get the values for the arrays from the user
//  printf("Enter the elements for array 1!\n");
//  for (int i = 0; i < size; i++) {
//    printf("Enter Element %d: ", i + 1);
//    scanf("%d", &array1[i]);
//  }
//  printf("\n");
//  printf("Enter the elements for array 2!\n");
//  for (int i = 0; i < size; i++) {
//    printf("Enter Element %d: ", i + 1);
//    scanf("%d", &array2[i]);
//  }
//  // Sum the corresponding array elements and store them in array 3
//  for (int i = 0; i < size; i++) {
//    array3[i] = array1[i] + array2[i];
//  }
//  // Print the values of array 3
//  printf("\nThe elements in array 3 are:\n");
//  for (int i = 0; i < size; i++) {
//    printf("%d ", array3[i]);
//  }
//  printf("\n");
//  // Free the allocated memory
//  free(array1);
//  free(array2);
//  free(array3);
//
//  return 0;
//}

//6

//#include <stdio.h>
//#include <stdlib.h>
//
//int main() {
//  int size;
//  int *array= (int *) malloc(size * sizeof(int));
//  int new_elements;
//
//  // Get the size of the array from the user
//  printf("Enter the size of the array: ");
//  scanf("%d", &size);
//
//  // Get the values for the array from the user
//  printf("Enter the elements for the array!\n");
//  for (int i = 0; i < size; i++) {
//    printf("Enter Element %d: ", i + 1);
//    scanf("%d", &array[i]);
//  }
//
//  // Print the values of the array
//  printf("The elements in the array are:\n");
//  for (int i = 0; i < size; i++) {
//    printf("%d ", array[i]);
//  }
//  
//
//  // Add a new element to the array
//    printf("\nHow many new elements do you want to add? ");
//    scanf("%d", &new_elements);
//
//    array = (int *) realloc(array, (size + new_elements) * sizeof(int));
//
//    for (int i = size; i < size + new_elements; i++)
//    {
//        printf("Enter Element %d: ", i + 1);
//        scanf("%d", &array[i]);
//    }
//
//    printf("The elements in the array are:\n");
//    for (int i = 0; i < size + new_elements; i++)
//    {
//        printf("%d ", array[i]);
//    }
//    printf("\n");
//
//    free(array);
//    return 0;
//}


