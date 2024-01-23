#include <iostream>

using namespace std;

template <typename T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    T pop() {
        if (isEmpty()) {
            throw out_of_range("Stack is empty");
        }

        T value = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;

        return value;
    }

    bool isEmpty() const {
        return head == nullptr;
    }

    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }

    LinkedList<T> clone() const {
        LinkedList<T> clonedList;
        Node* current = head;

        while (current != nullptr) {
            clonedList.push(current->data);
            current = current->next;
        }

        return clonedList;
    }

    LinkedList<T> operator+(const LinkedList<T>& other) const {
        LinkedList<T> result = clone();
        Node* current = other.head;

        while (current != nullptr) {
            result.push(current->data);
            current = current->next;
        }

        return result;
    }

    LinkedList<T> operator*(const LinkedList<T>& other) const {
        LinkedList<T> result;
        Node* current = head;

        while (current != nullptr) {
            if (other.contains(current->data)) {
                result.push(current->data);
            }
            current = current->next;
        }

        return result;
    }

    bool contains(const T& value) const {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void display() const {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

