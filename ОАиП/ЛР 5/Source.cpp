#include <iostream>
#include <fstream>
using namespace std;

struct list
{
	int number;
	list* next;
};

void insert(list*& p, float value); //���������� ������� � ������ ������
void printList(list* p);       //����� ������ 
void toFile(list*& p);         //������ � ����
void fromFile(list*& p);       //���������� �� �����
void summ(list* p);           //����� �� �������
void menu(void);               //����� ���� 


int main()
{
	setlocale(LC_CTYPE, "Russian");
	list* first = nullptr;
	int choice; float value;
	menu();    // ������� ���� 
	cout << " ? ";
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
		case 1:  	cout << "������� ������ ";
			cin >> value;
			insert(first, value);
			printList(first);
			break;
		case 2:   toFile(first);
			break;
		case 3:   fromFile(first);
			break;
		case 4:   summ(first);
			break;
		default:  cout << "������������ �����" << endl;
			menu(); break;
		}
		cout << "?  ";
		cin >> choice;
	}
	return 0;
}

void insert(list*& p, float value) //���������� ������� � ������ ������
{
	list* newP = new list;
	if (newP != NULL)     //���� �� �����?  
	{
		newP->number = value;
		newP->next = p;
		p = newP;
	}
	else
		cout << "�������� ���������� �� ���������" << endl;
}

void printList(list* p)  //����� ������ 
{
	if (p == NULL)
		cout << "������ ����" << endl;
	else
	{
		cout << "������:" << endl;
		while (p != NULL)
		{
			cout << "-->" << p->number;
			p = p->next;
		}
		cout << "-->NULL" << endl;
	}
}

void toFile(list*& p)
{
	list* temp = p;
	list buf;
	ofstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	while (temp)
	{
		buf = *temp;
		frm.write((char*)&buf, sizeof(list));
		temp = temp->next;
	}
	frm.close();
	cout << "������ ������� � ���� mList.dat\n";
}

void fromFile(list*& p)          //���������� �� �����
{
	list buf, * first = nullptr;
	ifstream frm("mList.dat");
	if (frm.fail())
	{
		cout << "\n ������ �������� �����";
		exit(1);
	}
	frm.read((char*)&buf, sizeof(list));
	while (!frm.eof())
	{
		insert(first, buf.number);
		cout << "-->" << buf.number;
		frm.read((char*)&buf, sizeof(list));
	}
	cout << "-->NULL" << endl;
	frm.close();
	p = first;
	cout << "\n������ ������ �� ����� mList.dat\n";
}
void summ(list* p) 
{
	float sum=0;
	if (p == NULL) {
		cout << "������ ����" << endl;
	}
	else
	{
		cout << "�����:" << endl;
		while (p != NULL)
		{
			if ( p->number < 0 && p->number % -5==0)
			{
				sum += (p->number);
				p = p->next;

			}

			else {
				cout << sum << ", ��� ��� ��� ������������� ����� ������� 5" << endl;
				break;
			}
			
		}
cout << sum<<endl;
	}
	
}

void menu(void)     //����� ���� 
{
	cout << "�������� �����:" << endl;
	cout << " 1 - ���� �������" << endl;
	cout << " 2 - ������ ������ � ����" << endl;
	cout << " 3 - ������ ������ �� �����" << endl;
	cout << " 4 - ����� ����� �� �������" << endl;
	cout << " 5 - �����" << endl;
}
