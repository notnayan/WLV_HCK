import java.util.HashMap;
import java.util.Scanner;

public class BankingSystem {
    BankingSystem(String bankName){
        System.out.println("\n\t"+bankName+" BANKING SYSTEM\n");
    }
    private String userName;
    private Float amount;
    private int choice;

    String getUsername(){
        return this.userName;
    }
    void setUsername(String userName){
        this.userName=userName;
    }

    Float getAmount(){
        return this.amount;
    }
    void setAmount(float amount)
    {
        this.amount=amount;
    }
    HashMap<String, Float> userInfo=new HashMap<>();

    Boolean checkAccount(String userName){
        userName=userName.toLowerCase();
        if(userInfo.containsKey(userName))
        {
            return  true;
        }
        else
        {
            return  false;
        }

    }

    void createAccount(String userName,float amount){
        userName=userName.toLowerCase();
        if (checkAccount(userName))
        {
            System.out.println("Account already exist");
        }
        else {
            if(amount>=0)
            {
                userInfo.put(userName,amount);
                System.out.println("Successfully created account");
            }
            else {
                System.out.println("Please! input valid information");
            }
        }

    }

    Boolean amountValidator(float amount){
        if(amount<0)
        {
            return false;
        }
        else {
            return true;
        }
    }

    void depositAmount(String userName,float amount)
    {

        userName=userName.toLowerCase();
        if(checkAccount(userName))
        {
            float currentAmount=userInfo.get(userName);
            userInfo.replace(userName,amount+currentAmount);
            System.out.println("Successfully deposited");
        }
        else {
            System.out.println("Cannot find the user");
        }

    }
    void withdraw(String userName,float amount)
    {

        userName=userName.toLowerCase();
        if(checkAccount(userName))
        {
            float currentAmount=userInfo.get(userName);
            userInfo.replace(userName,amount-currentAmount);
            System.out.println("Successfully withdrawn");
        }
        else {
            System.out.println("Cannot find the user");
        }

    }
    
    void checkBalance(Scanner sc)
    {
        System.out.println("Enter username");
        String username= sc.nextLine();
        if(checkAccount(username))
        {
            float amount=userInfo.get(username.toLowerCase());
            System.out.println("Your balance is:"+amount);

        }
        else
        {
            System.out.println("Account not found!!!");
        }
    }

    void exit()
    {
        System.out.println("Thank you for using!!!");
    }

    void userChoice(Scanner sc,int choice){
           this.choice=choice;

            switch (choice)
            {
                case 0:
                    exit();
                    choice=0;
                    break;
                case 1:
                    sc.nextLine();
                    System.out.println("Enter username");
                    userName=sc.nextLine();
                    System.out.println("Enter amount");
                    amount=sc.nextFloat();
                    createAccount(userName,amount);
                    break;

                case 2:
                    sc.nextLine();
                    System.out.println("Enter username");
                    String username=sc.nextLine();
                    System.out.println("Enter amount to deposit");
                    float amount=sc.nextFloat();
                    depositAmount(username,amount);
                    break;
                case 3:
                    sc.nextLine();
                    System.out.println("Enter username");
                    String name=sc.nextLine();
                    System.out.println("Enter amount to withdraw");
                    float amt=sc.nextFloat();
                    withdraw(name,amt);
                    break;

                case 4:
                    sc.nextLine();
                    checkBalance(sc);
                    break;

                default:
                    System.out.println("Invalid input");
                    break;
            }

    }
}

class BankingTransaction{
    BankingTransaction(){
        System.out.println("----Welcome----");
        System.out.println("----To----");
        System.out.println("---NIC ASIA----");
    }
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        BankingSystem bank=new BankingSystem("NIC ASIA");
        int choice=-1;
       while (choice!=0)
       {
           System.out.println("Enter key for the operations\n");
           System.out.println("""
                    0. Exit
                    1. Create Account
                    2. Deposit Amount
                    3. Withdraw Amount
                    4. Check Balance

                    """);
           choice=sc.nextInt();
           bank.userChoice(sc,choice);
       }
    }
}