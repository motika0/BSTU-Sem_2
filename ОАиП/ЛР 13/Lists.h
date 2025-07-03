#ifndef LISTS_H
#define LISTS_H

#include <iostream>
#include <string>

using namespace std;

struct Node {
    int key;
    string name;
    string rector;
    Node* next;
};

class List {
    Node* head;
    List();
    void insert(int key, string name, string rector);
    Node* search(int key);
    void display();
};
#endif // LISTS_H
