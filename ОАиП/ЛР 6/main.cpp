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
        cout << "\n1. Добавить нового больного\n"
            << "2. Удалить больного\n"
            << "3. Вывести информацию о больных\n"
            << "4. Выход\n";
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Введите фамилию больного: ";
            cin >> patient.surname;
            cout << "Введите номер карточки: ";
            cin >> patient.cardNumber;
            cout << "Введите фамилию врача: ";
            cin >> patient.doctorSurname;
            cout << "Введите номер кабинета: ";
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
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор. Попробуйте снова.\n";
        }
    } while (choice != 4);

    return 0;
}
