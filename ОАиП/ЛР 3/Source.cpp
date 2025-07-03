#include <iostream>
#include <Windows.h>
using namespace std;
int input(int size, int num);
int output(int num);
int find(char lastName[]);

typedef struct Abitur
{
	char nameuniv[50];
	char adres[50];
	char perechen[50];
	char kpgpks[100];
	char money[100];

} ABIT;

int number; int number2;
FILE* f; errno_t err;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	int choice; char perechen[50];
	cout << "Справочник абитуриента\n";
	do
	{
		cout << "\n1.Ввод данных с клавиатуры и запись в файл\n";
		cout << "2.Вывод данных из файла\n";
		cout << "3.Поиск по Специальности\n";
		cout << "0.Выход из программы\n\n";
		cout << "Введите номер операции: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "Введите количество универститетов: ";
			cin >> number;
cout << "Введите число специальностей: ";
			cin >> number2;
			input(number,number2);  break;
		case 2: 
			output(number2); break;
		case 3: {  cout << "Введите Cпециальность: ";
            cin >> perechen;
			find(perechen); break;     }
		case 0: exit(0);  break;
		}
	} while (choice != 0);
	return 0;
}

int input(int size, int num)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ABIT buf = {' ',};
	if (!fopen_s(&f, "base.text", "ab"))
	{
		for (int p = 0; p < size; p++)
		{
			cout << "Название универститета: "; cin >> buf.nameuniv;
			cout << "Адрес: "; cin >> buf.adres;
			for (int i = 0; i < num; i++) {
            cout << "Специальность: "; cin >> buf.perechen;
			cout << "Конкурс прошлого года по каждой специальности: "; cin >> buf.kpgpks;
			cout << "Размер оплаты при договорном обучении: "; cin >> buf.money;
			}

			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "Ошибка открытия файла";
	}
	return 0;
}


int output(int num)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	ABIT buf;
	if (!fopen_s(&f, "base.text", "rb"))
	{
		cout << "\nУниверситет\tАдрес\tПеречень специальностей\tКонкурс прошлого года по каждой специальности\tРазмер оплаты при договорном обучении\n" ;
		fread(&buf, sizeof(buf), 1, f);
		while (!feof(f))
		{
			cout << buf.nameuniv << "\t  " << buf.adres;
			for (int i = 0; i < num; i++) {
cout<< "\t  "<<buf.perechen << "\t  " << buf.kpgpks << "\t  "<< buf.money<<endl;
			}
				
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

int find(char lastName[50])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool flag = false;  ABIT buf;
	if (!fopen_s(&f, "base.text", "rb"))
	{
		while (!feof(f))
		{
			fread(&buf, sizeof(buf), 1, f);
			if (strcmp(lastName, buf.perechen) == 0)   //сравнение строк
			{
				cout << "\nУниверситет    Адрес    Перечень специальностей     Конкурс прошлого года по каждой специальности    Размер оплаты при договорном обучении\n";
				cout << buf.nameuniv << "\t  " << buf.adres << "\t  " << buf.perechen << "\t  " << buf.kpgpks << "\t  " << buf.money << endl;
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
