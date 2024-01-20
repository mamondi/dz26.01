#pragma once
#include <iostream>
#include <Windows.h>

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

    void Show() const {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

