#include "Heap.h"
#include <iostream>
using namespace std;

heap::CMP cmpAAA(void* a1, void* a2)  //������� ���������
{
    AAA* A1 = (AAA*)a1;
    AAA* A2 = (AAA*)a2;

    heap::CMP rc = heap::EQUAL;

    if (A1->x > A2->x)
        rc = heap::GREAT;
    else if (A2->x > A1->x)
        rc = heap::LESS;

    return rc;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int k, i, choice;

    heap::Heap h1 = heap::create(30, cmpAAA);

    for (;;)
    {
        cout << "1 - ����� ���� �� �����" << endl;
        cout << "2 - �������� �������" << endl;
        cout << "3 - ������� ������������ �������" << endl;
        cout << "4 - ������� ����������� �������" << endl;
        cout << "5 - ������� i-�� �������" << endl;
        cout << "0 - �����" << endl;
        cout << "�������� �����" << endl;

        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(0);
        case 1:
            h1.scan(0);
            break;
        case 2:
        {
            AAA* a = new AAA;
            cout << "������� ����" << endl;
            cin >> k;
            a->x = k;
            h1.insert(a);
        }
        break;
        case 3:
            h1.extractMax();
            break;
        case 4:
            h1.extractMin();
            break;
        case 5:
        {
            cout << "������� i:";
            cin >> i;
            h1.extractI(i);
        }
        break;
        default:
            cout << endl << "������� �������� �������!" << endl;
        }
    }

    return 0;
}