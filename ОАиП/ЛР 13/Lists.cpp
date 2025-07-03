#include "Lists.h"

List::List() {
    head = NULL;
}

void List::insert(int key, string name, string rector) {
    Node* newNode = new Node;
    newNode->key = key;
    newNode->name = name;
    newNode->rector = rector;
    newNode->next = head;
    head = newNode;
}

Node* List::search(int key) {
    Node* current = head;
    while (current != NULL) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void List::display() {
    Node* current = head;
    while (current != NULL) {
        cout << "Год создания: " << current->key << ", Имя: " << current->name << ", Ректор: " << current->rector << endl;
        current = current->next;
    }
}
