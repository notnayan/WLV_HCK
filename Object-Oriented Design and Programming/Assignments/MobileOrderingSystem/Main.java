
// Import java.util.Scanner is a Java language statement that imports the Scanner class from the java.util package. 
import java.util.Scanner;
// Import java.util.ArrayList; is a statement in the Java programming language that allows us to use the ArrayList class from the java.util package in our code.
import java.util.ArrayList;
// Import java.util.List; is a statement in the Java programming language that allows us to use the List interface from the java.util package in our code.
import java.util.List;

// Create a class that is the main class of the application
public class Main {
    public static void main(String[] args) {
        // Create a Scanner object to read user input from the command line
        Scanner scanner = new Scanner(System.in);

        // Initialize an empty list to store user data
        List<User> userData = new ArrayList<User>();

        // Print a welcome message
        System.out.println("-------------------------------------------------------------------------------------");
        System.out.println("------------------WELCOME TO AZA ONLINE MOBILE ORDERING PROGRAM----------------------");
        System.out.println("-------------------------------------------------------------------------------------");

        // Enter a loop that waits for the user to make a decision
        while (true) {

            // Print a message asking the user to choose between signing up or quitting
            System.out.println("Please Enter 1 for Sign Up!\nPlease Enter 2 for Quit!");

            // Read the user's decision
            int decision = scanner.nextInt();

            // If the user chose to sign up, call the signup method of the SignUp class
            if (decision == 1) {
                System.out.println("\nWELCOME TO THE SIGN UP PAGE!\n----------------------------");
                SignUp.signup(scanner, userData);
                continue;

                // If the user chose to quit, break out of the loop and print a goodbye message
            } else if (decision == 2) {
                System.out.println("\nThank you for using the Application!\nQutting the program.....");
                break;

                // If the user entered any other value, also break out of the loop and print a
                // goodbye message
            } else {
                System.out.println("\nThank you for using the Application!\nQutting the program.....\n");
                break;
            }
        }
    }
}
