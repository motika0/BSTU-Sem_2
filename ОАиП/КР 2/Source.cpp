#include <iostream>
#include "myStack.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Rus");
    int choice, k, max= 0;
    Stack* myStk = new Stack; //выделение памяти для стека
    myStk = NULL;             //инициализация первого элемента	
    for (;;)
    {
        cout << "Выберите команду:" << endl;
        cout << "1 - Добавление и вывод элементов в стек" << endl;
        cout << "2 - Запись в файл" << endl;
        cout << "3 - Выход" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Число случайных чисел k: ";
            cin >> k;
            for (int i = 0; i < k; ++i) {
            int randomNum = rand() % 100; // Генерируем случайное число от 0 до 99
            push(randomNum, myStk);
            if (randomNum > max) {
                max = randomNum;
            }
            cout << randomNum << " ";
        }
            cout << "\n Максимальный элемент стека: ";
            cout << max<<"\n"; break;
        case 2: toFile(myStk);  break;
        case 3: return 0; break;
        }
    }
    return 0;
}



