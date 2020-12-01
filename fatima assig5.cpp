//fatima abdalla alageb
//the second band
//computer department
#include <iostream>
using namespace std;

class LinkedList {
    class Node {
    public:
        int data;
        Node *next = nullptr;

        Node(int item) {
            data = item;
            next = nullptr;
        }
    };

public:
    Node *head = nullptr;
    Node *last = nullptr;
    int size = 0;


    int pop() {                
        int item = head->data;
        head = head->next;
        return item;
    }

    void add(int item) {      
        if (head == nullptr) {
            head = new Node(item);
            last = head;
        } else {
            Node *newNode = new Node(item);
            last->next = newNode;
            last = newNode;
        }
        size++;
    }

    bool isEmpty() const {
        if (head == nullptr) return true;
        return false;
    }

    void removeHead() {
        Node *nextOfTheHead = head->next;
        delete head;
        head = nextOfTheHead;
        size--;

    }

    void removeLast() {
        Node *current = head;
        int i = 0;
        while (i < size - 2) {
            current = current->next;
            i++;
        }
        Node *lastOfTheLast = current;
        delete last;
        last = lastOfTheLast;
        last->next = nullptr;
        size--;
    }

    int search(int item) const {
        Node *current = head;
        int counter = 0;
        while (current != last) {
            if (current->data == item) return counter;
            current = current->next;
            counter++;
        }
        return counter;
    }

    void removeAt(int index) {
        Node *lastOfCurrent = head;
        for (int i = 0; i < index - 1; ++i)
            lastOfCurrent = lastOfCurrent->next;

        Node *current = lastOfCurrent->next;
        lastOfCurrent->next = current->next;
        delete current;
        size--;


    }

    friend ostream &operator<<(ostream &os, const LinkedList &list) {
        if (list.isEmpty()) {
            os << "[ ]";
            return os;
        }
        Node *lastNode = list.head;
        os << "[";
        while (lastNode->next != nullptr) {
            os << lastNode->data << ", ";
            lastNode = lastNode->next;
        }
        os << lastNode->data << "]";
        return os;
    }
};

int main() {
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);
    list.add(7);



    list.removeHead();
    list.removeLast();
    cout << "Remove at index 3" << endl;
    list.removeAt(3);
    cout << "Index of 5: " << list.search(5) << endl;

    cout << "List Head: " << list.head->data << endl;
    cout << "List Last: " << list.last->data << endl;
    cout << "List: " << list << endl;
    cout << "List size: " << list.size << endl;


                                                                                           
class Stack { 
public:
    class Node {
    public:
        int data;
        Node *next = nullptr;

        Node(int item) {
            data = item;
            next = nullptr;
        }
    };

    Node *last = nullptr;
    int size = 0;

    void push(int item) { 
        if (last == nullptr)
            last = new Node(item);
        else {
            Node *newNode = new Node(item);
            newNode->next = last;
            last = newNode;
        }
        size++;

    }

    int pop() {
        Node *lastOfTheLast = last->next;
        int item = last->data;
        delete last;
        last = lastOfTheLast;
        return item;
    }

    int isEmpty() const {
        return size == 0;
    }

    int peek() const {
        return last->data;
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    cout << "Stack Peek: " << stack.peek() << endl;
    cout << "Stack Pop: " << stack.pop() << endl;
    cout << "Stack Pop: " << stack.size << endl;




class Queue {

public:
    class Node {
    public:
        int data;
        Node *next = nullptr;
        Node *previous = nullptr;

        Node(int item) {
            data = item;
        }
    };

    Node *head = nullptr;
    Node *last = nullptr;
    int size = 0;

    void enqueue(int item) {
        if (head == nullptr) {
            head = new Node(item);
            last = head;
        } else {
            Node *newNode = new Node(item);
            newNode->previous = head;
            head->next = newNode;
            last = newNode;
        }
        size++;
    }

    int dequeue() {
        int item = head->data;
        Node *newHead = head->next;
        delete head;
        head = newHead;

        return item;
    }

    int front() {
        return head->data;
    }

    int rear() {
        return last->data;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    cout << queue.dequeue() << endl;
    cout << queue.front() << endl;
    cout << queue.rear() << endl;
return 0;}



