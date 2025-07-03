#include "Hash.h"
#include <iostream>
#define DEL nullptr
Object create(int size, int(*getkey)(void*))
{
    return Object(size, getkey);
}

Object::Object(int size, int(*getkey)(void*))
{
    N = 0;
    this->size = size;
    this->getKey = getkey;
    this->data = new void* [size];

    for (int i = 0; i < size; ++i)
        data[i] = nullptr;
}

bool Object::insert(void* d)
{
    bool b = false;

    if (N != size)
    {
        for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0); i != size && !b; j = Next_hash(j, size, ++i))
        {
            if (data[j] == nullptr || data[j] == DEL)
            {
                data[j] = d;
                N++;
                b = true;
            }
        }
    }

    return b;
}

int Object::searchInd(int key)
{
    int t = -1;
    bool b = false;

    if (N != 0)
    {
        for (int i = 0, j = HashFunction(key, size, 0); data[j] != nullptr && i != size && !b; j = HashFunction(key, size, ++i))
        {
            if (data[j] != DEL && getKey(data[j]) == key)
            {
                t = j;
                b = true;
            }
        }
    }

    return t;
}

void* Object::search(int key)
{
    int t = searchInd(key);

    return (t >= 0) ? (data[t]) : (nullptr);
}

void* Object::deleteByKey(int key)
{
    int i = searchInd(key);

    void* t = data[i];

    if (t != nullptr)
    {
        data[i] = DEL;
        N--;
    }

    return t;
}

bool Object::deleteByValue(void* d)
{
    return (deleteByKey(getKey(d)) != nullptr);
}

void Object::scan(void(*f)(void*))
{
    for (int i = 0; i < this->size; i++)
    {
        std::cout << "Элемент " << i;

        if ((this->data)[i] == nullptr)
            std::cout << ": пусто" << std::endl;
        else
            if ((this->data)[i] == DEL)
                std::cout << ": удален" << std::endl;
            else
                f((this->data)[i]);
    }
}

int HashFunction(int key, int size, int p) // Хеш-функция
{
    double key2 = 5 * ((0.6180339887499 * key) - int((0.6180339887499 * key)));

    return (p + key) % size;
}

int Next_hash(int hash, int size, int p)
{
    return (hash + 5 * p + 3 * p * p) % size;
}
