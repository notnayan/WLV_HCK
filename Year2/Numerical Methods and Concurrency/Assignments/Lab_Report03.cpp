#include <stdio.h>
#include <string.h>
//1 

//int main()
//{
// int input;
//    printf("Enter the number of elements you wish to enter: ");
//    scanf("%d", &input);
//    int arr[input];
//
//    for (int i = 0; i < input; i++)
//    {
//        printf("Enter Element %d: ", i + 1);
//        scanf("%d", &arr[i]);
//    }
//	int max = arr[0];
//	for (int i = 1; i < sizeof(arr) / sizeof(int) ; i++)
//	{
//		if (max < arr[i])
//		{
//			max = arr[i];
//		}
//	}
//    printf("The largest element in the array is: %d",max);
//	return 0;
//}

//2

//int main ()  
//{  
//    char arr1[30], arr2[30];  
//    int len1, len2, num, i, j, found = 0, not_found = 0;  
//      
//    printf ("Input the first string: ");  
//    scanf ("%s", arr1);  
//      
//    printf ("Input the second string: ");  
//    scanf ("%s", arr2);  
//      
//    len1 = strlen (arr1);  
//    len2 = strlen (arr2);  
//      
//    if (len1 == len2)  
//    {  
//        num = len1; 
//        for (i = 0; i < num; i++)  
//        {  
//            found = 0;  
//            for (j = 0; j < num; j++)  
//            {   
//                if (arr1[i] == arr2[j])  
//                {  
//                    found = 1;  
//                    break;  
//                }  
//            }  
//              
//            if (found == 0)  
//            {  
//                not_found = 1; 
//                break;  
//            }  
//        }  
//        if (not_found == 1)  
//            printf ("\n%s and %s strings are not an anagram of each other.", arr1, arr2);  
//        else  
//            printf ("\n%s and %s strings are an anagram of each other.", arr1, arr2);     
//    }  
//    else  
//        printf ("Both string must contains same number of character to be the anagram of string. ");  
//          
//    return 0;     
//} 

//3

//int main()
//{
//    int input;
//    printf("Enter the number of elements you wish to enter: ");
//    scanf("%d", &input);
//    int arr[input];
//    
//    for (int i = 0; i < input; i++)
//    {
//        printf("Enter Element %d: ", i + 1);
//        scanf("%d", &arr[i]);
//    }
//    
//    printf("The distinct elements of the array are:\n");
//    
//    for (int i = 0; i < input; i++)
//    {
//        int j;
//        for (j = i + 1; j < input; j++)
//        {
//            if (arr[i] == arr[j])
//            {
//                break;
//            }
//        }
//        if (j == input)
//		{
//			printf("%d ", arr[i]);
//		}
//            
//    }
//    
//    return 0;
//}

//4

//int main()
//{
//    int input;
//    printf("Enter the number of elements you wish to enter: ");
//    scanf("%d", &input);
//    int arr[input];
//    
//    for (int i = 0; i < input; i++)
//    {
//        printf("Enter Element %d: ", i + 1);
//        scanf("%d", &arr[i]);
//    }
//    
//    int temp;
//    printf("The elements of the array in ascending order are:\n");
//    for (int i = 0; i < input; i++)
//    {
//        for (int j = i + 1; j < input; j++)
//        {
//            if (arr[i] > arr[j])
//            {
//                temp = arr[i];
//                arr[i] = arr[j];
//                arr[j] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < input; i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}

//5

//int main()
//{
//    int input;
//    printf("Enter the number of elements you wish to enter: ");
//    scanf("%d", &input);
//    int arr[input];
//    
//    for (int i = 0; i < input; i++)
//    {
//        printf("Enter Element %d: ", i + 1);
//        scanf("%d", &arr[i]);
//    }
//    
//    int sum = 0, count = 0;
//    for (int i = 0; i < input; i++)
//    {
//        if (arr[i] % 5 == 0 && arr[i] % 2 != 0 && arr[i] % 3 != 0)
//        {
//        	sum += arr[i];
//            count++; 
//		}
//            
//    }
//    printf("\nThe sum is %d\n", sum);
//    printf("The count is %d", count);
//    return 0;
//}

//6

//int main()
//{
//    int arr1[2][2] = {{1, 6}, {1, 7}};
//    int arr2[2][2] = {{6, 9}, {4, 2}};
//    int rsize = 2;
//    int csize = 2;
//
//    for (int col = 0; col < csize; col++)
//    {
//        for (int row = 0; row < rsize; row++)
//        {
//            printf("%d ", arr1[row][col] + arr2[row][col]);
//        }
//        printf("\n");
//    }
//    printf("Above is the sum of corrsponding elements!");
//    return 0;
//}


