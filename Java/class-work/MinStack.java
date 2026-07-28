class Node {
    Node next;
    Node prev;
    int value;
    int minAtThisPoint;

    Node(int value, int minAtThisPoint) {
        this.value = value;
        this.minAtThisPoint = minAtThisPoint;
    }
}

public class MinStack {
    static Node head;
    static Node tail;

    static void push(int val) {
        if (head == null) {
            head = new Node(val, val);
            tail = head;
            return;
        }
        int min = tail.minAtThisPoint > val ? val : tail.minAtThisPoint;
        Node newNode = new Node(val, min);
        tail.next = newNode;
        newNode.prev = tail;
        tail = newNode;
    }

    static void pop() {
        if (head == null) {
            return;
        }
        if (head.next == null) {
            head = null;
            tail = null;
            return;
        }
        Node previous = tail.prev;
        tail.prev = null;
        previous.next = null;
        tail = previous;
    }

    static int top() {
        if (head == null) {
            return -1; // the stack is empty
        }
        return tail.value;
    }

    static int getMin() {
        if (head == null) {
            return -1; // the stack is empty
        }
        return tail.minAtThisPoint;
    }

    public static void main(String[] args) {
        MinStack stack = new MinStack();
        stack.push(-2);
        stack.push(0);
        stack.push(-3);
        System.out.println(stack.getMin());
        stack.pop();
        System.out.println(stack.top());
        System.out.println(stack.getMin());
    }
}