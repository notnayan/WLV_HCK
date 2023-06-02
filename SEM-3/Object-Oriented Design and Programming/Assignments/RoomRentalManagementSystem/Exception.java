class UserNotFound extends RuntimeException {
    // Constructor for the UserNotFound exception class
    public UserNotFound(String e) {
        // Call the superclass constructor with the provided error message
        super(e);
    }
}

class InputMissMatchException extends RuntimeException {
    // Constructor for the InputMissMatchException exception class
    public InputMissMatchException(String e) {
        // Call the superclass constructor with the provided error message
        super(e);
    }
}