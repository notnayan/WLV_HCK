
// Import the Pattern and Matcher classes from the java.util.regex package
import java.util.regex.Pattern;
import java.util.regex.Matcher;

// Import the Year class from the java.time package
import java.time.Year;

// Create a class that validates the user input
public class Validation {

    // The method checks if the full name is at least 4 characters long
    static boolean validateName(String fullName) {
        if (fullName.length() < 4) {
            return false;
        }
        return true;
    }

    // The method uses a regular expression to check if the mobile number is a valid
    // format
    static boolean validateMobileNum(String mobileNumber) {
        // Regular expression for validating mobile number
        String regex = "^0\\d{9}$";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(mobileNumber);
        return matcher.matches();
    }

    /*
     * The method checks if the password and confirm password match, and also if the
     * password is in the correct format
     */
    static boolean validatePassword(String password, String confirmPassword) {
        if (password.equals(confirmPassword)) {
            // Regular expression for validating password
            final String regex = "^[a-zA-Z]+[@&][0-9]+$";
            Pattern pattern = Pattern.compile(regex);
            Matcher matcher = pattern.matcher(password);
            return matcher.matches();
        }
        return false;
    }

    /*
     * The method checks if the DOB is in the correct format (dd/mm/yyyy) and if the
     * user is at least 21 years old
     */
    static boolean validateDOB(String DOB) {
        // Regular expression for validating DOB format
        String regex = "\\d{2}/\\d{2}/\\d{4}";
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(DOB);

        // Extract the year from the DOB string
        int year = Integer.parseInt(DOB.split("/")[2]);
        // Get the current year
        int currentYear = Integer.parseInt(Year.now().toString());

        // Check if DOB is in correct format and if user is at least 21 years old
        if (!matcher.matches() || (currentYear - year) < 21) {
            return false;
        }
        return matcher.matches();
    }
}
