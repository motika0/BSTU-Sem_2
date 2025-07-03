#include <iostream>
#include <Windows.h>
using namespace std;
int input(int size);
int output();
int find(char fy[50]);

typedef struct Gorozhanin
{
    char F[50];
    char I[50];
    char O[50];
    int day[50];
    char month[50];
    char year[50];
    char gender[50];
    char address[50];
} GR;

int number;
FILE* f; errno_t err;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(0, "");
    int choice; char year[50];
    do
    {
        cout << "\n1 - Ввод данных\n";
        cout << "2 - Вывод данных\n";
        cout << "3 - Поиск по году\n";
        cout << "4 - Выход из программы\n\n";
        cout << "Введите номер операции: ";
        cin >> choice;
        switch (choice)
        {
        case 1: cout << "Введите количество людей: ";
            cin >> number;
            input(number);  break;
        case 2:
            output(); break;
        case 3: {  cout << "Введите год: ";
            cin >> year;
            find(year); break;     }
        case 4: exit(0);  break;
        }
    } while (choice != 4);
    return 0;
}

int input(int size)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    GR buf = { ' ', };
    if (!fopen_s(&f, "f.txt", "ab"))
    {
        for (int p = 0; p < size; p++)
        {
            cout << "Горожанин №" << p + 1 << ": " << endl;
            cout << "Фамилия: "; cin >> buf.F;
            cout << "Имя: "; cin >> buf.I;
            cout << "Отчество: "; cin >> buf.O;
            cout << "День рождения: "; cin >> buf.day;
            cout << "Месяц рождения: "; cin >> buf.month;
            cout << "Год рождения: "; cin >> buf.year;
            cout << "Пол(м/ж): "; cin >> buf.gender;
            cout << "Адрес: "; cin >> buf.address;

            fwrite(&buf, sizeof(buf), 1, f);
        }
        fclose(f);
    }
    else {
        cout << "Ошибка открытия файла";
    }
    return 0;
}


int output()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    GR buf;
    if (!fopen_s(&f, "f.txt", "rb"))
    {
        cout << "\nФамилия\tИмя\tОтчество\tДень\tМесяц\tГод рождения\tПол\tАдрес\n";
        fread(&buf, sizeof(buf), 1, f);
        while (!feof(f))
        {
            cout << buf.F << "\t  " << buf.I << "\t  " << buf.O << "\t  " << buf.day << "\t  " << buf.month << "\t  " << buf.year << "\t  " << buf.gender << "\t  " << buf.address << endl;
            fread(&buf, sizeof(buf), 1, f);
        }
        cout << endl;
        fclose(f);
    }
    else
    {
        cout << "Ошибка открытия файла";
    }
    return 0;
}

int find(char fy[50])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool flag = false;  GR buf;
    if (!fopen_s(&f, "f.txt", "rb"))
    {
        while (!feof(f))
        {
            fread(&buf, sizeof(buf), 1, f);
            if (strcmp(fy, buf.year) == 0)
            {
                cout << "\nФамилия\tДень\tМесяц\tГод рождения\tПол\tАдрес\n";
                cout << buf.F << "\t  " << buf.I << "\t  " << buf.O << "\t  " << buf.day << "\t  " << buf.month << "\t  " << buf.year << "\t  " << buf.gender << "\t  " << buf.address << endl;
                flag = true; break;
            }
        }
        fclose(f);
        if (!flag) cout << "Ничего не найдено\n";
    }
    else
    {
        cout << "Ошибка открытия файла";
    }
    return 0;
}