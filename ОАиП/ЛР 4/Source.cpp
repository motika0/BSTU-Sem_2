#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

enum Type {
    LUXURY, SINGLE, TWICE, TRIPLE, APARTMENT
};

struct Client {
    string passport;
    unsigned arrdate; // ������� ���� ��� �������� ���� �������
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
        cout << "������� ����� ��������: ";
        cin >> newClient.passport;
        cout << "������� ����� ������� (1-31): ";
        cin >> newClient.arrdate;
        cout << "������� ����� ����� (1-31): ";
        cin >> newClient.depdate;
        cout << "������� ����� �������: ";
        cin >> newClient.roomNumber;
        int type;
        cout << "������� ��� ������� (0 - ����, 1 - �������, 2 - �������, 3 - �������, 4 - �����������): ";
        cin >> type;
        newClient.type = static_cast<Type>(type);

        clients[numClients++] = newClient;
        cout << "����� ��������" << endl;
    }
    else {
        cout << "���������, � ����� ���� ������ ���" << std::endl;
    }
}

void seeClients() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < numClients; ++i) {
        cout << "������ ��������: " << clients[i].passport << ", ����� ��������: " << clients[i].arrdate
            << ", ����� �����: " << clients[i].depdate << ", ���� �������� " << clients[i].roomNumber
            << ", ��� �������: " << clients[i].type << endl;
    }
}

void findClient() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    unsigned int searchDate;
    cout << "������� ����� �������� �������, �������� ������ �����: ";
    cin >> searchDate;

    for (int i = 0; i < numClients; ++i) {
        if (clients[i].arrdate == searchDate) 
        {
            cout << "������ ������: ����� �������� - " << clients[i].passport << ", ������  " << searchDate << " �����" << endl;
        }
        else {
            cout << "������ �� ������." << endl;
            break;
        }
    }
}

void deleteClients() {
    numClients = 0;
    cout << "������ �������� ��������." <<endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    int choice;

    do {
        cout << "\n������ �������� ���������\n";
        cout << "1. �������� �������\n";
        cout << "2. ������ ���������\n";
        cout << "3. ����� ������� �� ����� ��������\n";
        cout << "4. �������� ������\n";
        cout << "5. �������� ������ ����������� ����\n";
        cout << "������� �����: ";
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
            cout << "���������� ������.\n";
            break;
        default:
            cout << "�������� �����\n";
        }

    } while (choice != 5);

    return 0;
}