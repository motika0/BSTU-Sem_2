#ifndef HASH_CHAIN_H
#define HASH_CHAIN_H

#include <iostream>
#include <string>
#include "Lists.h"

using namespace std;

const int TABLE_SIZE = 2;

class Hash_Chain {
    List* table[TABLE_SIZE];
    Hash_Chain();
    int hashFunction(int key);
    void insert(int key, string name, string rector);
    void search(int key);
    void display();
};

#endif // HASH_CHAIN_H