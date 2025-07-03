#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

enum Type {
    LUXURY, SINGLE, TWICE, TRIPLE, APARTMENT
};

struct Client {
    string passport;
    unsigned arrdate; // Битовое поле для хранения даты приезда
    unsigned depdate;
    int roomNumber;
    Type type;
};

const int max_clients = 100;
Client clients[max_clients];
int numClients = 0;

void addClient() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    using namespace std;
    if (numClients < max_clients) {
        Client newClient;
        cout << "Введите номер паспорта: ";
        cin >> newClient.passport;
        cout << "Введите число приезда (1-31): ";
        cin >> newClient.arrdate;
        cout << "введите число ухода (1-31): ";
        cin >> newClient.depdate;
        cout << "Введите номер комнаты: ";
        cin >> newClient.roomNumber;
        int type;
        cout << "Введите тип комнаты (0 - люкс, 1 - однушка, 2 - двойная, 3 - тройная, 4 - апартаменты): ";
        cin >> type;
        newClient.type = static_cast<Type>(type);

        clients[numClients++] = newClient;
        cout << "Гость добавлен" << endl;
    }
    else {
        cout << "Изивините, в отеле мест больше нет" << std::endl;
    }
}

void seeClients() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < numClients; ++i) {
        cout << "Данные паспорта: " << clients[i].passport << ", Число прибытия: " << clients[i].arrdate
            << ", Число ухода: " << clients[i].depdate << ", Дата прибытия " << clients[i].roomNumber
            << ", Тип комнаты: " << clients[i].type << endl;
    }
}

void findClient() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    unsigned int searchDate;
    cout << "Введите число прибытия клиента, которого хочете найти: ";
    cin >> searchDate;

    for (int i = 0; i < numClients; ++i) {
        if (clients[i].arrdate == searchDate) 
        {
            cout << "Клиент найден: номер паспорта - " << clients[i].passport << ", прибыл  " << searchDate << " числа" << endl;
        }
        else {
            cout << "Клиент не найден." << endl;
            break;
        }
    }
}

void deleteClients() {
    numClients = 0;
    cout << "Запись клиентов сброшена." <<endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        cout << "\nСписок клиентов гостиницы\n";
        cout << "1. Добавить клиента\n";
        cout << "2. Список клтиентов\n";
        cout << "3. Найти клиента по числу прибытия\n";
        cout << "4. Сбросить список\n";
        cout << "5. Звершить работу консольного окна\n";
        cout << "Введите число: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addClient();
            break;
        case 2:
            seeClients();
            break;
        case 3:
            findClient();
            break;
        case 4:
            deleteClients();
            break;
        case 5:
            cout << "Завершение работы.\n";
            break;
        default:
            cout << "Неверный число\n";
        }

    } while (choice != 5);

    return 0;
}