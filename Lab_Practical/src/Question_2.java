public class Question_2 {

    class QueueNode {
        int data;
        QueueNode next;

        QueueNode(int a) {
            data = a;
            next = null;
        }
    }

    QueueNode front, rear;

    Question_2() {
        front = rear = null;
    }

    void push(int a) {
        QueueNode temp = new QueueNode(a);

        if (rear == null) {
            front = rear = temp;
            return;
        }

        rear.next = temp;
        rear = temp;
    }

    int pop() {
        if (front == null) {
            return -1;
        }

        int val = front.data;
        front = front.next;

        if (front == null) {
            rear = null;
        }

        return val;
    }
}