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
	cout << "���������� ����������\n";
	do
	{
		cout << "\n1.���� ������ � ���������� � ������ � ����\n";
		cout << "2.����� ������ �� �����\n";
		cout << "3.����� �� ��������\n";
		cout << "0.����� �� ���������\n\n";
		cout << "������� ����� ��������: ";
		cin >> choice;
		switch (choice)
		{
		case 1: cout << "������� ���������� ����: ";
			cin >> number;
			input(number);  break;
		case 2:
			output(); break;
		case 3: {  cout << "������� ��������: ";
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
			cout << "�����: "; cin >> buf.avtor;
			cout << "��������: "; cin >> buf.name;
			cout << "������: "; cin >> buf.rasdel;
			cout << "�����: "; cin >> buf.hobby;
			cout << "�������� ���������: "; cin >> buf.dom;
			fwrite(&buf, sizeof(buf), 1, f);
		}
		fclose(f);
	}
	else {
		cout << "������ �������� �����";
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
			cout <<"�����:" << buf.avtor << "\n ��������:" << buf.name << "\n ������:" << buf.rasdel << "\n �����:" << buf.hobby << "\n ���.���:" << buf.dom << endl;

			fread(&buf, sizeof(buf), 1, f);
		}
		cout << endl;
		fclose(f);
	}
	else
	{
		cout << "������ �������� �����";
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
			if (strcmp(Name, buf.name) == 0)   //��������� �����
			{
				cout << "�����:" << buf.avtor << "\n ��������:" << buf.name << "\n ������:" << buf.rasdel << "\n �����:" << buf.hobby << "\n ���.���:" << buf.dom << endl;
				flag = true; break;
			}
		}
		fclose(f);
		if (!flag) cout << "������ �� �������\n";
	}
	else
	{
		cout << "������ �������� �����";
	}
	return 0;
}
