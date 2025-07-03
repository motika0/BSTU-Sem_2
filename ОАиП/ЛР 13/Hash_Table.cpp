#include "Hash_Chain.h"

Hash_Chain::Hash_Chain() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = new List();
    }
}

int Hash_Chain::hashFunction(int key) {
    return key % TABLE_SIZE;
}

void Hash_Chain::insert(int key, string name, string rector) {
    int index = hashFunction(key);
    table[index]->insert(key, name, rector);
}

void Hash_Chain::search(int key) {
    int index = hashFunction(key);
    Node* result = table[index]->search(key);
    if (result != NULL) {
        cout << "Универстите нашелся:" << endl;
        cout << "Год создания: " << result->key << endl;
        cout << "Имя: " << result->name << endl;
        cout << "Ректор: " << result->rector << endl;
    }
    else {
        cout << "Универстите с таким годом " << key << " не найден." << endl;
    }
}

void Hash_Chain::display() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ":" << endl;
        table[i]->display();
    }
}
