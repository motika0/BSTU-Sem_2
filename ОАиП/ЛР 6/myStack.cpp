// myStack.cpp
#include "myStack.h"
#include <iostream>
using namespace std;


Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    destroyStack();
}

void Stack::push(const Patient& patient) {
    Node* newNode = new Node;
    newNode->data = patient;
    newNode->next = top;
    top = newNode;
}

void Stack::pop() {
    setlocale(0, "rus");
    if (isEmpty()) {
        cout << "���� ����. ���������� ������� �������.\n";
        return;
    }

    Node* temp = top;
    top = top->next;
    delete temp;
}

void Stack::display() const {
    setlocale(0, "rus");
    Node* current = top;
    while (current) {
        cout << "�������: " << current->data.surname
            << ", ����� ��������: " << current->data.cardNumber
            << ", ����: " << current->data.doctorSurname
            << ", ����� ��������: " << current->data.roomNumber << "\n";
        current = current->next;
    }
}

bool Stack::isEmpty() const {
    return top == nullptr;
}

void Stack::destroyStack() {
    while (!isEmpty()) {
        pop();
    }
}
