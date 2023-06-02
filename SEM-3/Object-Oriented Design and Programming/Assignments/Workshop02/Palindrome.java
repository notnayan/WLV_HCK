import java.util.Scanner;

// Created a public class with a method that prints the home screen.
public class Palindrome 
{
    void display()
    {
        System.out.println("-------------------------------");
        System.out.println("WELCOME TO PALINDROME CHECKER:");
        System.out.println("-------------------------------");
    }
}

// Created a child class which checks if the user input is palindromic number or not.
class IsPalindromeNum extends Palindrome
{
    int rem;
    int temp;
    int sum = 0;
    int num;

/* Stored the number temporarily and calculated the remainder then added it to the product 
of sum and 10 and finally divided the number by 10. Finally, checked the sum and printed 
the result accordindly.*/ 
    void checkPalindromeNum(){
        temp = num;
        while(temp>0)
        {
            rem = temp % 10;
            sum = (sum*10)+rem;
            temp /= 10;
        }

        if(num==sum)
        {
            System.out.println("The number '" + num + "' is a Palindromic Number!\n");
        }
    
        else
        {
            System.out.println("The number '" + num + "' is not a Palindromic Number!\n");
        }
    
    }
}

// Created another child class which checks if the user input is palindromic word or not.
class IsPalindromeChar extends Palindrome
{
    String input;
    String result;

/* Firstly, we find the midpoint of the word then store the characters from 0th index till midpoint in a variable.
 * Then the loop is ran backwards and the reverse characters are stored in another variable.
 * Finally, the if the length is odd or even whatever the case might be the result is printed accordingly.*/
      void checkPalindromeChar()
      {
        String rev = "";
        int mid = input.length()/2;
        result=input.substring(0, mid);
        for(int i = result.length() - 1; i>=0 ; i--)
        {
            rev += result.charAt(i);
        }

        if(input.substring((input.length() % 2 == 0 ? mid : mid + 1),input.length()).equalsIgnoreCase(rev))
        {
            System.out.println("The word '" + input + "' is a Palindromic Word!\n");
        }
        else{
            System.out.println("The word '" + input + "' is not a Palindromic Word!\n");
        }

      }
}  

// Created a main class in which the object of classes has been made and functions are called and the program is run.
class Main
{    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        IsPalindromeNum palnum = new IsPalindromeNum();
        IsPalindromeChar palchar = new IsPalindromeChar();

// Here, depending on the user input, whether it is a number or word, the scanner identifies it and calls on the respective function.
        palnum.display();
            System.out.println("Enter any number/word: ");
            if (scanner.hasNextInt())
            {
                palnum.num =scanner.nextInt();
                palnum.checkPalindromeNum();
            } else {
                palchar.input = scanner.nextLine();
                palchar.checkPalindromeChar();
            }
        scanner.close();
    }
    
}

