
//Import java.util.Scanner is a Java language statement that imports the Scanner class from the java.util package.
import java.util.Scanner;
//Import java.util.List; is a statement in the Java programming language that allows us to use the List interface from the java.util package in our code.
import java.util.List;

//  Create a class for signing up a new user.
public class SignUp {

    // Method for signing up a new user.
    public static void signup(Scanner scanner, List<User> userData) {

        // Create a new User object to store the user's data
        User user = new User();

        // Loop until the sign up process is successful
        while (true) {
            try {

                // Prompt the user for their full name and set it for the User
                System.out.println("Please enter your full name: ");
                scanner.nextLine();
                String fullname = scanner.nextLine();
                user.setFullName(fullname);

                // Prompt the user for their mobile number and set it for the User
                System.out.println("Please enter your mobile number: ");
                String mobileNumber = scanner.next();
                user.setMobileNumber(mobileNumber);

                // Prompt the user two times, one for their password and second to confirm their
                // password and set it for the User
                System.out.println("Please enter your password: ");
                String password = scanner.next();

                System.out.println("Please confirm your password: ");
                String confirmPassword = scanner.next();
                user.setPassword(password, confirmPassword);

                // Prompt the user for their date of birth and set it for the User
                System.out.println("Please enter your date of birth (DD/MM/YYYY): ");
                String DOB = scanner.next();
                user.setDOB(DOB);

                // Print success message and add user to the user data list
                System.out.println(
                        "\nThank you for your patience!\nYour Sign Up process has been completed successfully!\n");
                System.out.println("USERS:");
                userData.add(user);
                for (int i = 0; i < userData.size(); i++) {
                    System.out.println((i + 1) + ") " + userData.get(i).getFullName());
                }
                System.out.println("\n");
                break;

            }
            // Print error message and loop again
            catch (Error e) {
                System.out.println(e.getMessage());
                continue;
            }
        }

    }
}
