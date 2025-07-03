#include <iostream>
#include <Windows.h>
using namespace std;
int input(int size);
int output();
int find(char Name[50]);

typedef struct library
{
	char avtor[50];
	char name[50];
	char rasdel[50];
	char hobby[100];
	char dom[100];
	

} BL;

int number;
FILE* f; errno_t err;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int choice; char name[50];
	cout << "Справочник библиотеки\n";
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по названию\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество книг: ";
			cin >> number;
			input(number);  break;
		case 2:
			output(); break;
		case 3: {  cout << "Введите название: ";
			cin >> name;
			find(name); break;     }
		case 0: exit(0);  break;
		}
	} while (choice != 0);
	return 0;
}

int input(int size)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	BL buf = { ' ', ' ' , ' ', ' ' , ' '};
	if (!fopen_s(&f, "base.txt", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Автор: "; cin >> buf.avtor;
			cout << "Название: "; cin >> buf.name;
			cout << "Раздел: "; cin >> buf.rasdel;
			cout << "Хобби: "; cin >> buf.hobby;
			cout << "Домашнее хозяйство: "; cin >> buf.dom;
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
	BL buf;
	if (!fopen_s(&f, "base.txt", "rb"))
	{
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout <<"Автор:" << buf.avtor << "\n Название:" << buf.name << "\n Раздел:" << buf.rasdel << "\n Хобби:" << buf.hobby << "\n Дом.хоз:" << buf.dom << endl;

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

int find(char Name[50])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool flag = false;  BL buf;
	if (!fopen_s(&f, "base.txt", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(Name, buf.name) == 0)   //сравнение строк
			{
				cout << "Автор:" << buf.avtor << "\n Название:" << buf.name << "\n Раздел:" << buf.rasdel << "\n Хобби:" << buf.hobby << "\n Дом.хоз:" << buf.dom << endl;
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
