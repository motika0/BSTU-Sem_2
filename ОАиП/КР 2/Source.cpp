#include <iostream>
#include "myStack.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int choice, k, max= 0;
    Stack* myStk = new Stack; //��������� ������ ��� �����
    myStk = NULL;             //������������� ������� ��������	
    for (;;)
    {
        cout << "�������� �������:" << endl;
        cout << "1 - ���������� � ����� ��������� � ����" << endl;
        cout << "2 - ������ � ����" << endl;
        cout << "3 - �����" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "����� ��������� ����� k: ";
            cin >> k;
            for (int i = 0; i < k; ++i) {
            int randomNum = rand() % 100; // ���������� ��������� ����� �� 0 �� 99
            push(randomNum, myStk);
            if (randomNum > max) {
                max = randomNum;
            }
            cout << randomNum << " ";
        }
            cout << "\n ������������ ������� �����: ";
            cout << max<<"\n"; break;
        case 2: toFile(myStk);  break;
        case 3: return 0; break;
        }
    }
    return 0;
}



