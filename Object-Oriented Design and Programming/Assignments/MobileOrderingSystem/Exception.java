
/*
 *Create custom exception class for errors during sign-up process. 
 *Here, the custom Error class extends the RuntimeException class, which represents an exception that is thrown at runtime. 
 */
class Error extends RuntimeException {

    /*
     * Create a constructor for the Error class which takes a string parameter
     * called errorMessage that represents the error message to be displayed.
     */

    public Error(String errorMessage) {
        super(errorMessage + "\nPlease try again from the start!\n");
    }
}