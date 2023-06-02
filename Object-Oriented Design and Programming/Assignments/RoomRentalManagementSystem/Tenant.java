import java.util.Scanner;
import java.util.ArrayList;

// Abstract class representing a tenant in the rental system
abstract public class Tenant extends SystemUser implements TenantRights{
    abstract void viewLandlord();
    abstract void selectLandlord(ArrayList<LandLord> landlordData);

// Method to handle the tenant's login
    @Override
    public  void login(Scanner scanner){
        scanner.nextLine();
        // Print a welcome message
        System.out.println("Welcome Tenant");
        // Initialize a flag to control the loop
       boolean isNotQuit=true;
       // Loop until the tenant decides to logout
       while (isNotQuit)
       {
            // Print the menu options
           System.out.println("""

                    What would you like to do?

                    1) View Landlord
                    2) Select Landlord
                    3) Leave Room
                    4) Due Payment
                    5) Review Landlord
                    6) Review Rental Property
                    7) Logout
                    """);
            // Get the user's choice
           int choice;
           try {
               choice = scanner.nextInt();
           } catch (InputMissMatchException e) {
            // If the user input is invalid, set the choice to an invalid value
               choice = 9;
           }
           // Perform the chosen action
           switch (choice) {
               case 1:
                   viewLandlord();
                   break;
               case 2:
                   selectLandlord(null);
                   break;
               case 3:
                   leaveRoom();
                   break;
               case 4:
                   duePayment();
                   break;
               case 5:
                   reviewLandlord(scanner);
                   break;
               case 6:
                   reviewRentalProperty(scanner);
                   break;
               case 7:
                   logout();
                   isNotQuit=false;
                   Main.authentication(scanner);
                   break;
               // Print an error message if the input is invalid    
               default:
                   System.out.println("Wrong Input!");
                   break;

           }

       }


    }
    @Override
    // Method to logout
    public void logout(){
        System.out.println("LogOut Successfully!!!");
    }
}

// Create interface with tenant rights
interface TenantRights {

    void leaveRoom();

    void duePayment();

    void reviewLandlord(Scanner sc);

    void reviewRentalProperty(Scanner sc);

}


class StudentTypeTenant extends Tenant{
    private String name;

    @Override
    public  void viewLandlord(){
        Main.viewLandlord();
    }

    @Override
    public void selectLandlord(ArrayList<LandLord> landlordData){
        System.out.println("Selected landlord successfully");
    };


    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
     @Override
     public void leaveRoom(){
         System.out.println("Room left Successfully");
     }

    @Override
    public  void duePayment(){
        System.out.println("Notified");
    }

    @Override
    public  void reviewLandlord(Scanner sc){
        sc.nextLine();
        System.out.println("Enter your review");
        String review=sc.nextLine();
        System.out.println("Thanks for you review!!!!s");
    }

    @Override
    public void reviewRentalProperty(Scanner sc){
        sc.nextLine();
        System.out.println("Enter your review");
        String review=sc.nextLine();
        System.out.println("Thanks for you review!!!!s");
    }

}

class FamilyTypeTenant extends Tenant{
    private String name;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }


    @Override
    void viewLandlord() {
        Main.viewLandlord();

    }

    @Override
    void selectLandlord(ArrayList<LandLord> landlordData) {
        System.out.println("Selected landlord successfully");

    }
    @Override
    public void leaveRoom() {
        System.out.println("Room left");
    }

    @Override
    public void duePayment() {
        System.out.println("Notified");
    }

    @Override
    public void reviewLandlord(Scanner sc) {
        sc.nextLine();
        System.out.println("Enter your review");
        String review=sc.nextLine();
        System.out.println("Thanks for you review!!!!");
    }

    @Override
    public void reviewRentalProperty(Scanner sc) {
        sc.nextLine();
        System.out.println("Enter your review");
        String review=sc.nextLine();
        System.out.println("Thanks for you review!!!!");
    }

}