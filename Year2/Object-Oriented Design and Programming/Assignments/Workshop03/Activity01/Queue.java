import java.util.ArrayList;

public class Queue {
    ArrayList<Integer> queue = new ArrayList<Integer>();

    void enqueue(int a) {
        queue.add(a);
    }

    void dequeue() throws Exception {
        if (queue.isEmpty()) {
            throw new Exception("Error: Queue Underflow");
        }
        queue.remove(0);
    }

    int peek() throws Exception {
        if (queue.isEmpty()) {
            throw new Exception("Error: Empty Queue");
        }
        return queue.get(0);
    }
}

class Main {
    public static void main(String[] args) throws Exception {
        Queue queue = new Queue();
        queue.enqueue(6);
        queue.enqueue(9);
        queue.dequeue();
        System.out.println(queue.peek());
        queue.enqueue(4);
        queue.dequeue();
        System.out.println(queue.peek());
        queue.enqueue(2);
        System.out.println(queue.peek());
    }
}
