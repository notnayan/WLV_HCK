// #include <stdio.h>

// 1.
// int main() {
//    int n, i, triangular_number;
//
//    printf("Enter a positive integer: ");
//    scanf("%d", &n);
//
//    for (i = 1; i <= n; i++) {
//        triangular_number = (i * (i + 1)) / 2;
//        printf("%d\n", triangular_number);
//    }
//
//    return 0;
//}

// 2.
// int main()
//{
//    int num, sum = 0, digit;
//    printf("Please enter a number: ");
//    scanf("%d", &num);
//
//    while (num != 0)
//    {
//        digit = num % 10;
//        sum += digit;
//        num = num / 10;
//    }
//
//    printf("The sum of the digits is: %d", sum);
//    return 0;
//}

// 3.
// int main()
//{
//    float first_number, second_number;
//    char op;
//
//
//    printf("Enter the first number: ");
//    scanf("%f", &first_number);
//
//    printf("Enter the second number: ");
//    scanf("%f", &second_number);
//
//        printf("Enter the operator (+, -, *, /, %%): ");
//        scanf("%s", &op);
//
//        switch (op)
//        {
//        case '+':
//            printf("The sum of the two numbers is %g\n", first_number + second_number);
//            break;
//
//        case '-':
//            printf("The difference of the two numbers is %g\n", first_number - second_number);
//            break;
//        case '*':
//            printf("The product of the two numbers is %g\n", first_number * second_number);
//            break;
//        case '/':
//            printf("The quotient of the two numbers is %g\n", first_number / second_number);
//            break;
//        case '%':
//            printf("The modulus of the two numbers is %d\n", (int)first_number % (int)second_number);
//            break;
//
//        default:
//
//            printf("Wrong input. Please enter a valid operator and try again!\n");
//            break;
//        }
//          return 0;
//
//    }

// 4.
// #include <stdio.h>
// #include <ctype.h>
//
// int main() {
//     char c;
//
//     printf("Enter a character: ");
//
//     while ((c = getchar()) != '\n') {
//         if (isupper(c)) {
//             printf("%c", tolower(c));
//         } else {
//             printf("%c", c);
//         }
//     }
//
//     return 0;
// }

// 5.
// int main()
//{
//     int final_score;
//
//     printf("Enter your final score: ");
//     scanf("%d", &final_score);
//
//     if (final_score >= 80 && final_score <= 100)
//     {
//         printf("Ace! You have cleared the examination with Distinction!\n");
//     }
//     else if (final_score >= 60 && final_score < 80)
//     {
//         printf("Outstanding! You have cleared the examination with 1st Division!\n");
//     }
//     else if (final_score >= 50 && final_score < 60)
//     {
//         printf("Impressive!  You have cleared the examination with 2nd Division!\n");
//     }
//     else if (final_score >= 40 && final_score < 50)
//     {
//         printf("Nice!  You have cleared the examination with 3rd Division!\n");
//     }
//     else if (final_score >= 0 && final_score < 40)
//     {
//         printf("Get Good! You failed   L\n");
//     }
//     else
//     {
//         printf("Incorrect input! Please try again!\n");
//     }
//     return 0;
// }

// 6.
// int main() {
//     char i, j;
//
//     for (i = 'A'; i <= 'E'; i++) {
//         for (j = 'A'; j <= i; j++) {
//             printf("%c ", i);
//         }
//         printf("\n");
//     }
//
//     return 0;
// }
