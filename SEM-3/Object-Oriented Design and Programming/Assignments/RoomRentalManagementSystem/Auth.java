import java.util.List;
import java.util.Map;

public class Auth {
    // Declare a private List variable called "userData" that stores a list of maps
    // Each map represents a set of user credentials, with keys "username", "password", and "role"
    private List<Map<String, String>> userData;

    public Auth() {
        // Create a new LoginData object and store its user data in the "userData" variable
        LoginData login = new LoginData();
        this.userData = login.getUserData();
    }
    // Method to retrieve the role of a user with the given username and password
    public String getUserRole(String username, String password) {
        // Iterate through each set of user credentials in the "userData" list
        for (Map<String, String> credential : userData) {
            // If the username and password provided match the current set of credentials, return the role
            if (credential.get("username").equals(username) && credential.get("password").equals(password)) {
                return credential.get("role");
            }
        }
        // If no matching credentials are found, throw a runtime exception
        throw new RuntimeException();
    }
}