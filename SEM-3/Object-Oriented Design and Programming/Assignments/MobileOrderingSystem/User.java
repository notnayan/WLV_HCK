
// Create a class that represents a user 
class User {

    /*
     * Create four private fields: fullName, mobileNumber, password, and DOB
     * (date of birth).
     * These fields store the user's full name, mobile phone number, password,
     * and date of birth, respectively.
     */
    private String fullName;
    private String mobileNumber;
    private String password;
    private String DOB;

    /*
     * Create four public methods for each of the fields: getFullName,
     * getMobileNumber, getPassword, and getDOB, which return the values of the
     * corresponding fields.
     * Also create four public methods for each of the fields: setFullName,
     * setMobileNumber, setPassword, and setDOB, which allow the values of the
     * corresponding fields to be set.
     * These setter methods include validation checks using the Validation class to
     * ensure that the data being set is valid.
     */
    public String getFullName() {
        return fullName;
    }

    /*
     * Here, the setFullName method checks that the full name is valid using the
     * validateName method of the Validation class.
     * If the data is not valid, the setter method throws an error.
     */
    public void setFullName(String fullName) {
        if (Validation.validateName(fullName)) {
            this.fullName = fullName;
        } else {
            throw new Error("Please enter valid full name.");
        }
    }

    public String getMobileNumber() {
        return mobileNumber;
    }

    /*
     * Here, setmobileNumber method checks that the password is valid using the
     * validateMobileNum method. If the data is not valid, the setter method throws
     * an error.
     */
    public void setMobileNumber(String mobileNumber) {
        if (Validation.validateMobileNum(mobileNumber)) {
            this.mobileNumber = mobileNumber;
        } else {
            throw new Error("Please enter valid mobile number which starts with 0 and is of 10-digits.");
        }
    }

    
    public String getPassword() {
        return password;
    }

    /*
     * Here, setPassword method checks that the password is valid using the
     * validatePassword method. If the data is not valid, the setter method throws
     * an error.
     */
    public void setPassword(String password, String confirmPassword) {
        if (Validation.validatePassword(password, confirmPassword)) {
            this.password = password;
        } else {
            throw new Error(
                    "Please re-check your password! Must have:\n1. Alphabets\n2. @ or &\n3. Numericals \n4. Both password match or not.");
        }

    }

    public String getDOB() {
        return DOB;
    }

    /*
     * Here, setDOB method checks that the date of birth is valid using the
     * validateDOB method. If the data is not valid, the setter method throws
     * an error.
     */
    public void setDOB(String DOB) {
        if (Validation.validateDOB(DOB)) {
            this.DOB = DOB;
        } else {
            throw new Error(
                    "Please re-check your Date Of Birth! Input must be in format (DD/MM/YYYY) or (MM/DD/YYYY) and age must be atleast 21.");
        }
    }

}