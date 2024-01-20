#pragma once
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
    Node* tail; 

public:
    LinkedList() : head(nullptr), tail(nullptr) {

    }

    ~LinkedList() {
        DeleteAll();
    }

    int Size() const {
        int size = 0;
        Node* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    void AddToHead(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void AddToTail(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void DeleteFromHead() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (!head) {
                tail = nullptr; 
            }
        }
    }

    void DeleteFromTail() {
        if (head) {
            if (head == tail) {
                delete head;
                head = tail = nullptr;
            }
            else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                delete tail;
                tail = temp;
                tail->next = nullptr;
            }
        }
    }

    void DeleteAll() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }

    void InsertAtPosition(const T& value, int position) {
        if (position < 0 || position > Size()) {
            cout << "Invalid position." << endl;
            return;
        }

        Node* newNode = new Node(value);

        if (position == 0) {
            AddToHead(value);
        }
        else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;

            if (position == Size() - 1) {
                tail = newNode;
            }
        }
    }

    void DeleteAtPosition(int position) {
        if (position < 0 || position >= Size()) {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 0) {
            DeleteFromHead();
        }
        else {
            Node* temp = head;
            for (int i = 0; i < position - 1; i++) {
                temp = temp->next;
            }

            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;

            if (position == Size() - 1) {
                tail = temp;
            }
        }
    }

    int Find(const T& value) const {
        Node* temp = head;
        int position = 0;
        while (temp) {
            if (temp->data == value) {
                return position;
            }
            temp = temp->next;
            position++;
        }
        return -1; 
    }

    int Replace(const T& oldValue, const T& newValue) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == oldValue) {
                temp->data = newValue;
                count++;
            }
            temp = temp->next;
        }
        return count == 0 ? -1 : count; 
    }

    void Reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void Show() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

