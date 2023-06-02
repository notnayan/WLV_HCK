import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

// Class containing main method for rental system
public class Main {
    // Private static list for landlord and both type of tenant data
    private static List<LandLord> landlordData = new ArrayList<LandLord>();
    private static List<StudentTypeTenant> stdTenantList = new ArrayList<StudentTypeTenant>();
    private static List<FamilyTypeTenant> famTenantList = new ArrayList<FamilyTypeTenant>();

    // Getter and Setter methods for both type of tenants
    public static List<StudentTypeTenant> getStudentTypeTenant() {
        return stdTenantList;
    }

    public static List<FamilyTypeTenant> getFamTenantList() {
        return famTenantList;
    }

    public static void setStdTenantList(List<StudentTypeTenant> list) {
        stdTenantList = list;
    }

    public static void setFamTenantList(List<FamilyTypeTenant> list) {
        famTenantList = list;
    }

    // Method to show the list of tenants to certain roles (Admin and Landlord)
    public static void showTenantList(String role) {
        // Check if the current user has the necessary role to view tenant list
        if (role.equals("Admin") || role.equals("Landlord")) {
            // If there are no family type or student tenants, print a message
            if (famTenantList.isEmpty()) {
                System.out.println("There are no family type tenant currently!!!");
            }
            // Otherwise, print the list of family and student type tenants
            else {
                System.out.println("Family type Tenant");
                for (int i = 0; i < famTenantList.size(); i++) {
                    System.out.println("ID:" + (i + 1));
                    System.out.println("Name:" + famTenantList.get(i).getName());
                }
            }
            System.out.println("\n");
            if (stdTenantList.isEmpty()) {
                System.out.println("There are no StdTenant available");
            } else {
                System.out.println("\tStudent type Tenant\n");
                for (int i = 0; i < stdTenantList.size(); i++) {
                    System.out.println("ID:" + (i + 1));
                    System.out.println("Name:" + stdTenantList.get(i).getName());
                }
            }

        }
        // If the current user does not have the necessary role, throw an error
        else {
            throw new AccessForbiddenError("Access denied");
        }
    }

    // Method to add a FamilyTypeTenant object to the famTenantList list
    public static void addFamilyTypeTenant(FamilyTypeTenant familyTypeTenant) {
        famTenantList.add(familyTypeTenant);
    }

    // Method to add a StudentTypeTenant object to the StudentTypeTenant list
    public static void addStudentTypeTenant(StudentTypeTenant studentTypeTenant) {
        stdTenantList.add(studentTypeTenant);
    }

    // Method to set the landlordData list to the provided landLordList
    public static void setLandlordData(List<LandLord> landLordList) {
        landlordData = landLordList;
    }

    // Method to print the information for all the landlords in the landlordData
    // list
    public static void viewLandlord() {
        if (landlordData.isEmpty()) {
            System.out.println("Sorry currently there are no landlords");
        } else {
            for (int i = 0; i < landlordData.size(); i++) {
                System.out.println("ID:" + (i + 1));
                System.out.println("Name:" + landlordData.get(i).getName());
                System.out.println("RentalCharge:" + landlordData.get(i).getRentalFee());
                System.out.println("Property:" + landlordData.get(i).getProperty());
                System.out.println("Contact:" + landlordData.get(i).getContactInfo());
                System.out.println("\n\n");
            }
        }
    }

    // Add a LandLord object to the landlordData list
    public static void addLandlord(LandLord landLord) {
        Main.landlordData.add(landLord);
    }

    // Return the landlordData list if the user is an Admin, throw an
    // AccessForbiddenError otherwise
    public static List<LandLord> getLandlordDetails(String role) {
        if (role.equals("Admin")) {
            return landlordData;
        } else {
            throw new AccessForbiddenError("Access Denied!!!!");
        }

    }

    // Attempt to authenticate the user with the given username and password. If
    // successful, return the user's role. If not, throw an exception
    public static void authentication(Scanner sc) {
        Auth auth = new Auth();
        String role;
        while (true) {
            System.out.println("Press Enter key to continue");
            sc.nextLine();
            System.out.println("Enter username");
            String username = sc.nextLine();

            System.out.println("Enter your Password");
            String password = sc.nextLine();

            try {
                role = auth.getUserRole(username, password);
                break;

            } catch (Exception e) {
                System.out.println(e.getMessage());
            }
        }
        // Once the role has been retrieved, proceed to login the user
        switch (role) {
            case "Admin":
                Admin admin = new Admin();
                admin.login(sc);
                break;

            case "Landlord":
                LandLord landLord = new LandLord();
                landLord.login(sc);
                break;

            case "Tenant":
                System.out.println("""
                        choose mode:
                        1.Family Type Tenant
                        2.Student Type Tenant
                        """);
                int choice = sc.nextInt();
                if (choice == 1) {
                    FamilyTypeTenant fam = new FamilyTypeTenant();
                    fam.login(sc);

                } else {
                    StudentTypeTenant studentTypeTenant = new StudentTypeTenant();
                    studentTypeTenant.login(sc);
                }

            default:
                System.out.println("NO function yet");
                break;

        }
    }

    public static void main(String[] args) {
        // Print welcome message
        System.out.println("------------------------------------------------------------");
        System.out.println("\t\tRENTAL MANAGEMENT SYSTEM\n");
        System.out.println("\t\tPlease LOGIN to Continue!");
        System.out.println("------------------------------------------------------------");
        // Create scanner object to read user input
        Scanner sc = new Scanner(System.in);
        // Call authentication method
        Main.authentication(sc);
        sc.close();

    }
}

class AccessForbiddenError extends RuntimeException {
    // Constructor to call superclass constructor with message
    public AccessForbiddenError(String e) {
        super(e);
    }
}