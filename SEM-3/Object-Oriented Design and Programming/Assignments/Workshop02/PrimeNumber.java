import java.util.Scanner;

// Created a public class with a method that prints the home screen
public class PrimeNumber {
    void display()
    {
        System.out.println("-------------------------------");
        System.out.println("WELCOME TO PRIME NUMBER CHECKER:");
        System.out.println("-------------------------------");
    }
}

// Created a child class which checks if the user input is prime or not
class IsPrimeNumber extends PrimeNumber
{
    int num ;
    void checkPrimeNumber()
    {
    int count = 0;
        
        // If the input divided by the loop number returns zero, increment the count by 1
        for (int i = 1; i < num; i++) {
            if (num % i == 0) 
            {
                count++;
            }
        }
        // Since prime number is a number that can be divided by 1 or itself, that means if the count has value greater than two it is not a prime number
        if(count <=2)
        {
            System.out.println("\nThe given number '" + num + "' is a Prime Number!\n");
        }
        else
        {
            System.out.println("\nThe given number '" + num + "' is not a Prime Number!\n");
        }
    }   
}

// Created a main class in which the object of classes has been made and functions are called and the program is run
class Main
{    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        IsPrimeNumber pmnm = new IsPrimeNumber();
        pmnm.display();
        System.out.println("Enter any number: ");
        pmnm.num = scanner.nextInt();
        pmnm.checkPrimeNumber();
        scanner.close();
    }          
}
        