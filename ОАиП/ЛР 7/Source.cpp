#include <iostream>
using namespace std;

struct myQue {
    char b;
    myQue* next;
};

struct Queue {
    myQue* front;
    myQue* rear;
    int maxSize;
    int currentSize;
};

Queue createQueue(int maxSize) {
    Queue q;
    q.front = nullptr;
    q.rear = nullptr;
    q.maxSize = maxSize;
    q.currentSize = 0;
    return q;
}

bool isEmpty(Queue& q) {
    return q.currentSize == 0;
}

void enQueue(Queue& q, myQue* newSymbol) {
    if (q.currentSize < q.maxSize) {
        if (isEmpty(q)) {
            q.front = newSymbol;
            q.rear = newSymbol;
        }
        else {
            q.rear->next = newSymbol;
            q.rear = newSymbol;
        }
        newSymbol->next = nullptr;
        q.currentSize++;
    }
    else {
        cout << "������� �����\n";
    }
}

void delQueue(Queue& q) {
    if (!isEmpty(q)) {
        myQue* temp = q.front;
        q.front = q.front->next;
        delete temp;
        q.currentSize--;
    }
}

myQue* peekQueue(Queue& q) {
    return q.front;
}

void releaseQueue(Queue& q) {
    while (!isEmpty(q)) {
        delQueue(q);
    }
}

void printQueue(Queue& q) {
    myQue* current = q.front;
    while (current != nullptr) {
        cout << current->b << " ";
        current = current->next;
    }
    cout << endl;
}

void checkDeleteSymbol(Queue& q, char symbol) {
    while (!isEmpty(q)) {
        if (peekQueue(q)->b == symbol) {
            delQueue(q);
            break;
        }
        else {
            delQueue(q);
        }
    }
}

void printMenu() {
    
    cout << "1. �������� ������ � �������\n";
    cout << "2. ������� ������ �� �������\n";
    cout << "3. ��������� � ������� �� ���������� �������\n";
    cout << "4. ������� ������� � ��������� ���������\n";
}

int main() {
    setlocale(0, "rus");
    int maxSize;
    cout << "������� ������������ ������ �������: ";
    cin >> maxSize;

    Queue q1 = createQueue(maxSize);
    char choice;
    char symbol;

    do {
        printMenu();
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case '1': {
            myQue* newSymbol = new myQue;
            cout << "������� ������ ��� ����������: ";
            cin >> newSymbol->b;
            enQueue(q1, newSymbol);
            break;
        }
        case '2':
            if (!isEmpty(q1)) {
                delQueue(q1);
                cout << "������ ������ �� �������\n";
            }
            else {
                cout << "������� �����\n";
            }
            break;
        case '3':
            cout << "������� ��������� ������: ";
            cin >> symbol;
            checkDeleteSymbol(q1, symbol);
            break;
        case '4':
            printQueue(q1);
            break;
        default:
            cout << "������������ �����\n";
        }
    } while (choice != '4');

    releaseQueue(q1);

    return 0;
}
