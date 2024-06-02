import java.util.ArrayList;

public class Stack {
    ArrayList<Integer> stack = new ArrayList<Integer>();

    void push(int a) {
        stack.add(a);
    }

    void pop() throws Exception {
        if (stack.isEmpty()) {
            throw new Exception("Error: Stack Underflow");
        }
        stack.remove(stack.size() - 1);
    }

    int peek() throws Exception {
        if (stack.isEmpty()) {
            throw new Exception("Error: Empty Stack");
        }
        return stack.get(stack.size() - 1);
    }
}

class Main {
    public static void main(String[] args) throws Exception {
        Stack stack = new Stack();
        stack.push(6);
        stack.push(9);
        stack.pop();
        System.out.println(stack.peek());
        stack.push(4);
        stack.push(2);
        stack.pop();
        System.out.println(stack.peek());
        stack.push(0);
        System.out.println(stack.peek());
    }
}