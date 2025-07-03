#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;

void push(char x, Stack*& myStk)   //Добавление элемента х в стек	
{
	Stack* e = new Stack;    //выделение памяти для нового элемента
	e->data = x;             //запись элемента x в поле data 
	e->next = myStk;         //перенос вершины на следующий элемент 
	myStk = e;               //сдвиг вершины на позицию вперед
}


void toFile(Stack*& myStk) //Запись в файл
{
	Stack* e = myStk;
	Stack buf;
	ofstream frm("mStack.dat");
	if (frm.fail())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	while (e)
	{
		buf = *e;
		frm.write((char*)&buf, sizeof(Stack)); //запись стека
		e = e->next;
	}
	frm.close();
	cout << "Стек записан в файл mStack.dat\n";
}



