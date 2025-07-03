// main.cpp
#include <iostream>
#include "myStack.h"
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "rus");
    Stack stack;
    int choice;
    Patient patient;

    do {
        cout << "\n1. �������� ������ ��������\n"
            << "2. ������� ��������\n"
            << "3. ������� ���������� � �������\n"
            << "4. �����\n";
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "������� ������� ��������: ";
            cin >> patient.surname;
            cout << "������� ����� ��������: ";
            cin >> patient.cardNumber;
            cout << "������� ������� �����: ";
            cin >> patient.doctorSurname;
            cout << "������� ����� ��������: ";
            cin >> patient.roomNumber;
            stack.push(patient);
            break;
        case 2:
            stack.pop();
            break;
        case 3:
            stack.display();
            break;
        case 4:
            cout << "����� �� ���������.\n";
            break;
        default:
            cout << "������������ �����. ���������� �����.\n";
        }
    } while (choice != 4);

    return 0;
}
