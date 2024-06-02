// Created a public class with private variables.
public class Animal 
{
    private String name;
    private String type;

// Created a constructur and passed the parameters.
    public Animal(String name, String type)
    {
    this.name = name;
    this.type = type;
    }   

// Used getter-setter method to retrieve and set the data.
    public String getName() 
    {
        return name;
    }

    public void setName(String name) 
    {
        this.name = name;
    }

    public String getType() 
    {
        return type;
    }

    public void setType(String type) 
    {
        this.type = type;
    }
    

}

// Created a child class having a function that displays the data from the get method.
class Wolf extends Animal
{
    private String role;
    public Wolf(String name, String type, String role) 
    {
        super(name, type);
        this.role = role;
    }

    void display()
    {
        System.out.println(this.getName());
        System.out.println(this.getType());
        System.out.println(role);
    }
}

// Created another child class that does the same function.
class Dog extends Animal
{
    public Dog(String name, String type) 
    {
        super(name, type);
    }

    void display()
    {
        System.out.println(this.getName());
    }
}

// Created a main class where object of the classes has been created and the functions are called.
class Main1
{
    public static void main(String[] args) 
    {
        Wolf wolfie = new Wolf("Wolfie", "Mammal", "Wolf have been known to be guardian deity in Japanese folklore");
        Dog dog = new Dog("Dog", "Mammal");
        wolfie.display();
        dog.display();
    }
}




