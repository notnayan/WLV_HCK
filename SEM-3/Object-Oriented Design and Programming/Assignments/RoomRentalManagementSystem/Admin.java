import java.util.List;
import java.util.Scanner;

class Admin extends SystemUser {

    final String role = "Admin";

    // Method to delete a landlord
    public void deleteLandLord(Scanner sc) {

        // Get a list of landlords
        List<LandLord> landLordList = Main.getLandlordDetails(role);

        // Check if the list is empty
        if (landLordList.isEmpty()) {
            System.out.println("No landlord available");
        } else {

            // View the landlords
            Main.viewLandlord();

            // Prompt the user to enter the ID of the landlord to delete
            System.out.println("Enter the ID to delete landlord");
            int choice = sc.nextInt();
            // Remove the chosen landlord from the list
            landLordList.remove(choice - 1);
            // Update the list of landlords
            Main.setLandlordData(landLordList);
            System.out.println("Successfully deleted landlord!!!");
        }
    }

    // Method to add a tenant
    public void addTenant(Scanner sc) {
        var choice = 1;
        boolean close = true;

        // Loop until the user makes a valid choice
        while (close) {
            // Prompt the user to select the type of tenant to add
            System.out.println("Which type of tenant you want to add?\n1. Family Type\n2. Student Type");
            choice = sc.nextInt();
            // Branch based on the user's choice
            switch (choice) {
                case 1 -> {
                    sc.nextLine();
                    // Create a new FamilyTypeTenant object
                    FamilyTypeTenant familyTypeTenant = new FamilyTypeTenant();
                    // Get the name of the family
                    System.out.println("Enter Surname of Family");
                    String name = sc.nextLine();
                    // Set the name of the family
                    familyTypeTenant.setName(name);
                    // Add the tenant to the list of tenants
                    Main.addFamilyTypeTenant(familyTypeTenant);
                    System.out.println("Added Successfully!!");
                    // Set the loop control variable to false to exit the loop
                    close = false;
                }
                case 2 -> {
                    // Create a new StudentTypeTenant object
                    StudentTypeTenant std = new StudentTypeTenant();
                    // Get the name of the student
                    sc.nextLine();
                    System.out.println("Enter  name of Student");
                    String stdName = sc.nextLine();
                    // Set the name of the student
                    std.setName(stdName);
                    // Add the tenant to the list of tenants
                    Main.addStudentTypeTenant(std);
                    System.out.println("Added Successfully!!");
                    // Set the loop control variable to false to exit the loop
                    close = false;
                }
                // Print default message
                default -> System.out.println("Input not valid");
            }
        }
    }

    // Method to add a landlord
    public void addLandlord(Scanner sc) {
        // Create a new LandLord object
        LandLord landLord = new LandLord();
        // Get the LandLord's details and set it accordingly
        sc.nextLine();
        System.out.println("Enter landlord name");
        String name = sc.nextLine();

        landLord.setName(name);
        System.out.println("Enter contact number");
        String contactNumber = sc.nextLine();
        landLord.setContactInfo(contactNumber);
        System.out.println("Enter Rental fee");
        int rentalFee = sc.nextInt();
        sc.nextLine();
        landLord.setRentalFee(rentalFee);
        System.out.println("Enter property");
        String property = sc.nextLine();
        landLord.setProperty(property);
        Main.addLandlord(landLord);
        System.out.println("Successfully added landlord");
    }

    // Method to remove a tenant
    public void removeTenant(Scanner sc) {
        // Get the lists of students and families
        List<StudentTypeTenant> std = Main.getStudentTypeTenant();
        List<FamilyTypeTenant> fam = Main.getFamTenantList();
        // Prompt the user to select the type of tenant to remove
        System.out.println("""
                Which type of tenant you want to remove?
                1. Family Type
                2. Student Type
                """);
        // Read the user's choice
        int choice;
        try {
            choice = sc.nextInt();
        } catch (RuntimeException e) {
            choice = 3;
        }
        // Loop until the user makes a valid choice
        boolean end = true;
        while (end) {
            // Branch based on the user's choice
            // Check the availibility of type of tenant, if present, view the tenants and
            // remove according to their ID and then update the list
            switch (choice) {
                case 1:
                    if (fam.isEmpty()) {
                        System.out.println("Sorry currently there tenant available");
                    } else {
                        Main.showTenantList(role);
                        System.out.println("Enter ID of tenant to remove");
                        int id = sc.nextInt() - 1;
                        fam.remove(id);
                        Main.setFamTenantList(fam);
                        end = false;
                        System.out.println("Successfully Removed!!!");
                    }
                    break;

                case 2:
                    if (std.isEmpty()) {
                        System.out.println("Sorry currently there tenant available");

                    } else {
                        Main.showTenantList(role);
                        System.out.println("Enter ID of tenant to remove");
                        int student = sc.nextInt() - 1;
                        std.remove(student);
                        Main.setStdTenantList(std);
                        end = false;
                        System.out.println("Successfully Removed!!!");
                        break;
                    }

                default:
                    // Print an error message if the user's choice is invalid
                    System.out.println("Wrong input");
                    break;
            }
        }
    }

    @Override
    // Method to log in as an admin
    public void login(Scanner sc) {
        // Print a welcome message
        System.out.println("Welcome");
        System.out.println("Login as admin");

        // Loop until the user chooses to exit
        int choice = 1;
        while (choice != 0) {
            // Print the menu of options
            System.out.println("""
                    0. Exit
                    1. Add Landlord
                    2. Update Landlord
                    3. Delete Landlord
                    4. Add Tenant
                    5. Update Tenant
                    6. Delete Tenant
                    7. Generate Report
                    8. ShowLandlord
                    9. ViewTenant
                    10. Logout
                    """);
            // Read the user's choice
            int userInput;
            try {
                userInput = sc.nextInt();
            } catch (Exception e) {
                userInput = 11;
            }
            // Set the loop control variable
            choice = userInput;
            // Branch based on the user's choice
            switch (userInput) {
                case 0 -> System.out.println("Exited, See you soon");
                case 1 -> addLandlord(sc);
                case 2 -> {
                    // View the landlords and allow the user to update
                    Main.viewLandlord();
                    updateLandlord(sc);
                }
                case 3 -> deleteLandLord(sc);
                case 4 -> addTenant(sc);
                case 5 -> updateTenant(sc);
                case 6 -> removeTenant(sc);
                case 7 -> generateReport();
                case 8 -> Main.viewLandlord();
                case 9 -> Main.showTenantList(role);
                case 10 -> {
                    // Log out and return to the authentication menu
                    logout();
                    choice = 0;
                    Main.authentication(sc);
                }
                default -> System.out.println("Wrong Input");
            }

        }

    }

    @Override
    // Method to log out
    public void logout() {
        System.out.println("Logged out Successfully!!");

    }

    // Method to update a landlord
    // Set and Get new details of LandLord
    public void updateLandlord(Scanner sc) {
        sc.nextLine();
        // Get the list of landlords
        List<LandLord> landLordList = Main.getLandlordDetails(role);
        System.out.println("Enter ID to Update landlord");
        int index = sc.nextInt() - 1;
        System.out.println("Enter the name");
        sc.nextLine();
        String name = sc.nextLine();
        System.out.println("Enter the RentalCharge");
        int rent = sc.nextInt();
        landLordList.get(index).setName(name);
        landLordList.get(index).setRentalFee(rent);
        System.out.println("Enter the property");
        sc.nextLine();
        String property = sc.nextLine();
        System.out.println("Enter the contact");
        String contact = sc.nextLine();
        landLordList.get(index).setProperty(property);
        landLordList.get(index).setContactInfo(contact);
        // Update the list of landlords
        Main.setLandlordData(landLordList);
        System.out.println("Successfully updated");
        // View the updated list of landlords
        Main.viewLandlord();
    }

    // Method to update a Tenant
    public void updateTenant(Scanner sc) {
        // Get the list of tenants
        List<StudentTypeTenant> std = Main.getStudentTypeTenant();
        List<FamilyTypeTenant> fam = Main.getFamTenantList();
        System.out.println("""
                Which type of tenant you want to Update?
                1. Family Type
                2. Student Type
                """);
        // Read the user's choice
        int choice;
        try {
            choice = sc.nextInt();
        } catch (RuntimeException e) {
            choice = 3;
        }
        // Loop until the update is complete
        boolean end = true;
        while (end) {
            // Branch based on the user's choice
            // Check the availibility of type of tenant, if present, view the tenants and
            // update the tenant details from the list accordindly
            switch (choice) {
                case 1:
                    if (fam.isEmpty()) {
                        System.out.println("Sorry currently there tenant available");
                    } else {
                        Main.showTenantList(role);
                        System.out.println("Enter ID of tenant to update");
                        int id = sc.nextInt() - 1;
                        System.out.println("Enter family sir name");
                        String sirName = sc.nextLine();
                        fam.get(id).setName(sirName);
                        Main.setFamTenantList(fam);
                        end = false;
                        System.out.println("Successfully Removed!!!");
                    }
                    break;

                case 2:
                    if (std.isEmpty()) {
                        System.out.println("Sorry currently there tenant available");

                    } else {
                        Main.showTenantList(role);
                        System.out.println("Enter ID of tenant to remove");
                        int student = sc.nextInt() - 1;
                        System.out.println("Enter Student name");
                        String name = sc.nextLine();
                        std.get(student).setName(name);
                        Main.setStdTenantList(std);
                        end = false;
                        System.out.println("Successfully Removed!!!");
                        break;
                    }
                    // If the user's choice was not valid, print an error message
                default:
                    System.out.println("Wrong input");
                    break;
            }
        }
    }

    // Method to generate a report
    public void generateReport() {
        // Print the title of the report
        System.out.println("\t________CURRENT REPORT______");
        // Get the number of landlords, family type tenants, and student type tenants
        int landlordLen = Main.getLandlordDetails(role).size();
        int famTenantLen = Main.getFamTenantList().size();
        int stdTenantLen = Main.getStudentTypeTenant().size();
        // Print the number of LandLords and the two type of tenants
        System.out.println("Currently there are " + landlordLen + " Landlords");
        System.out.println("Currently there are " + famTenantLen + " family type tenants");
        System.out.println("Currently there are " + stdTenantLen + " student type tenants");
    }
}