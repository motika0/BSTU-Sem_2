// myStack.h
#pragma once
using namespace std;
#include <string>

struct Patient {
    string surname;
    int cardNumber;
    string doctorSurname;
    int roomNumber;
};

class Stack {
public:
    Stack();
    ~Stack();

    void push(const Patient& patient);
    void pop();
    void display() const;

private:
    struct Node {
        Patient data;
        Node* next;
    };

    Node* top;

    // ѕриватные методы дл€ управлени€ списком
    bool isEmpty() const;
    void destroyStack();
};
