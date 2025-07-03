#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

#define HASHDEL (void*) -1

struct Object
{
    void** data;
    int size;
    int N;
    int(*getKey)(void*);
    bool insert(void*);
    int searchInd(int key);
    void* search(int key);
    void* deleteByKey(int key);
    bool deleteByValue(void*);
    void scan(void(*f)(void*));
};

static void* DEL = (void*)HASHDEL;

Object create(int size, int(*getkey)(void*));
int HashFunction(int key, int size, int p);
int Next_hash(int hash, int size, int p);

struct BankClient
{
    string fullName;
    int accountNumber;
    double balance;
    double interestRate;

    BankClient(string name, int accNum, double bal, double rate)
    {
        fullName = name;
        accountNumber = accNum;
        balance = bal;
        interestRate = rate;
    }

    BankClient() {}
};

int key(void* d)
{
    BankClient* client = (BankClient*)d;
    return client->accountNumber;
}

void BankClient_print(void* d)
{
    BankClient* client = (BankClient*)d;
    cout << "ФИО: " << client->fullName << ", Номер счета: " << client->accountNumber << ", Баланс: " << client->balance << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "rus");
    int siz = 10, choice, accNum;

    cout << "Введите размер хеш-таблицы: ";
    cin >> siz;

    Object H = create(siz, key);

    for (;;)
    {
        cout << "1 - вывод хеш-таблицы" << endl;
        cout << "2 - добавление клиента" << endl;
        cout << "3 - удаление клиента" << endl;
        cout << "4 - поиск клиента" << endl;
        cout << "0 - выход" << endl;
        cout << "Сделайте выбор: ";
        cin >> choice;

        switch (choice)
        {
        case 0: exit(0);
        case 1: H.scan(BankClient_print); break;
        case 2:
        {
            BankClient* newClient = new BankClient;
            string name;
            double balance, rate;

            cout << "Введите ФИО клиента: ";
            cin.ignore();
            getline(cin, name);

            cout << "Введите номер счета: ";
            cin >> accNum;

            cout << "Введите баланс: ";
            cin >> balance;

            cout << "Введите процентную ставку: ";
            cin >> rate;

            *newClient = BankClient(name, accNum, balance, rate);

            if (H.N == H.size)
                cout << "Таблица заполнена" << endl;
            else
                H.insert(newClient);
        }
        break;
        case 3:
        {
            cout << "Введите номер счета для удаления: ";
            cin >> accNum;
            H.deleteByKey(accNum);
        }
        break;
        case 4:
        {
            cout << "Введите номер счета для поиска: ";
            cin >> accNum;
            if (H.search(accNum) == NULL)
                cout << "Клиент не найден" << endl;
            else
                BankClient_print(H.search(accNum));
        }
        break;
        }
    }

    return 0;
}
