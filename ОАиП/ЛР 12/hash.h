#ifndef HASH_H
#define HASH_H

struct Object
{
    void** data;
    int size;
    int N;
    int(*getKey)(void*);
    Object(int size, int(*getkey)(void*));
    bool insert(void*);
    int searchInd(int key);
    void* search(int key);
    void* deleteByKey(int key);
    bool deleteByValue(void*);
    void scan(void(*f)(void*));
};

Object create(int size, int(*getkey)(void*));
int HashFunction(int key, int size, int p);
int Next_hash(int hash, int size, int p);

#endif
