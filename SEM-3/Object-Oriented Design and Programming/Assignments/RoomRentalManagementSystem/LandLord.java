import java.util.Scanner;

interface LandlordRights {
    // Method to give notice to a tenant
    void giveNotice();

    // Method to review a tenant
    void reviewTenant();

    // Method to request payment from a tenant
    void requestPayment();
}

public class LandLord extends SystemUser implements LandlordRights {
    // Declare a final string variable called "role" with the value "Landlord"
    final String role = "Landlord";

    // Implementation of the giveNotice method from the LandlordRights interface
    @Override
    public void giveNotice() {
    }

    // Implementation of the reviewTenant method from the LandlordRights interface
    @Override
    public void reviewTenant() {
    }

    // Implementation of the requestPayment method from the LandlordRights interface
    @Override
    public void requestPayment() {
    }

    // Implementation of the logout method from the SystemUser class
    @Override
    public void logout(

    ) {
        System.out.println("Successfully logout!!!");
    }

    // Method to add bill
    public void addBill(Scanner sc){
        sc.nextLine();
        System.out.println("Enter the name of tenant");
        String name= sc.nextLine();
        System.out.println("Enter amount");
        int amount=sc.nextInt();
        System.out.println(amount+" Rs has been added to Mr/miss "+ name);
    }

    // Implementation of the login method from the SystemUser class
    @Override
    public void login(Scanner scanner) {
        System.out.println("\tWelcome");
        System.out.println("Logged in as Landlord");

        // Display the menu and prompt the user to make a selection
        boolean exit = true;
        while (exit) {
            System.out.println("""
                    0. Exit
                    1. View Tenant
                    2. Add bill
                    3. View Number of Tenant
                    4. Logout
                    """);
            int choice = scanner.nextInt();
            switch (choice) {
                case 0:
                    System.out.println("Sucessfully Exited");
                    exit = false;
                    break;

                case 1:
                    try {
                        // View the list of tenants
                        Main.showTenantList(role);
                    } catch (Exception e) {
                        // Print the error message if an exception is thrown
                        System.out.println(e.toString());

                    }
                    break;

                case 2:
                    // Implement add bill feature
                    addBill(scanner);
                    break;

                case 3:
                    // Display the number of tenants in the system
                    System.out.println("There are "
                            + (Main.getFamTenantList().size() + Main.getStudentTypeTenant().size()) + " Tenant");
                    break;

                case 4:
                    // Logout and return to the login screen
                    logout();
                    exit = false;
                    Main.authentication(scanner);
                    break;

                default:
                    System.out.println("Incorrect input");
            }
        }

    }

    // Declare private variables for the name, property, contact info, and rental
    // fee of the landlord
    private String name;
    private String property;
    private String contactInfo;
    private int rentalFee;

    // Method to retrieve the name of the landlord
    public String getName() {
        return name;
    }

    // Method to set the name of the landlord
    public void setName(String name) {
        this.name = name;
    }

    // Method to retrieve the property owned by the landlord
    public String getProperty() {
        return property;
    }

    // Method to set the property owned by the landlord
    public void setProperty(String property) {
        this.property = property;
    }

    // Method to retrieve the contact info of the landlord
    public String getContactInfo() {
        return contactInfo;
    }

    // Method to set the contact info of the landlord
    public void setContactInfo(String contactInfo) {
        this.contactInfo = contactInfo;
    }

    // Method to retrieve the rental fee of the landlord's property
    public int getRentalFee() {
        return rentalFee;
    }

    // Method to set the rental fee of the landlord's property
    public void setRentalFee(int rentalFee) {
        this.rentalFee = rentalFee;
    }

    // Method to display the information of a given landlord
    public void displayLandlordInfo(LandLord landLord) {
        System.out.println("Name:" + landLord.getName());
        System.out.println("Contact:" + landLord.getContactInfo());
        System.out.println("Property:" + landLord.getProperty());
        System.out.println("RentalFee:" + landLord.getRentalFee());
    }

}