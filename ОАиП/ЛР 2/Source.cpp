#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    char buff[50];
   
    ofstream text1("t.txt");
    string str;
    int k;
    cout << "������� �����������(�� 50 ��������): ";
    getline(cin, str);
    text1 << str;
    text1.close();
    ifstream text2("t.txt");   
    if (!text2.is_open())
        cout << "���� �� ����� ���� ������!\n";
    else
    {
        text2.getline(buff, 50); 
        
        cout << buff << endl;  
        cout << "������� ����� �������� k: ";
        cin >> k;
        cout << endl;
        for (int i = 0; i < k; i++) {
            cout << buff[i];
        }
        cout << endl;
;        for (int i = k; i < sizeof(str)/sizeof(str[0]); i++) {
    cout << buff[i];
}
     
        text2.close();
        return 0;
    }

}
