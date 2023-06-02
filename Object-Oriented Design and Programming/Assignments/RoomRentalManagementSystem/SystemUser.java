import java.util.Scanner;

// Declare an abstract class called SystemUser
abstract class SystemUser {
    // Declare an abstract method called login which takes a Scanner as a parameter
    abstract public void login(Scanner sc);

    // Declare an abstract method called logout
    abstract public void logout();

}