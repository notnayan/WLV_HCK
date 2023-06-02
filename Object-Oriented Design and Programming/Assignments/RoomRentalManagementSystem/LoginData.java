import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class LoginData {
    // Declare a private List variable called "userData" that stores a list of maps
    // Each map represents a set of user credentials, with keys "username",
    // "password", and "role"
    private List<Map<String, String>> userData;
    // Initialize the "userData" list with default user data
    {
        // Create a new ArrayList to store the user data
        userData = new ArrayList<>();
        // Create a new map for the "admin" user
        Map<String, String> admin = new HashMap<String, String>();
        // Set the username, password, and role for the "admin" user
        admin.put("username", "@admin");
        admin.put("password", "password@123");
        admin.put("role", "Admin");
        // Add the "admin" map to the "userData" list
        userData.add(admin);

        // Create a new map for the "landlord" user
        Map<String, String> landlord = new HashMap<String, String>();
        // Set the username, password, and role for the "landlord" user
        landlord.put("username", "@landlord");
        landlord.put("password", "password@123");
        landlord.put("role", "Landlord");
        // Add the "landlord" map to the "userData" list
        userData.add(landlord);

        // Create a new map for the "tenant" user
        Map<String, String> tenant = new HashMap<String, String>();
        // Set the username, password, and role for the "tenant" user
        tenant.put("username", "@tenant");
        tenant.put("password", "password@123");
        tenant.put("role", "Tenant");
        // Add the "tenant" map to the "userData" list
        userData.add(tenant);

    }

    // Method to retrieve the "userData" list
    public List<Map<String, String>> getUserData() {
        return userData;
    }

}