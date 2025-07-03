#include "Hash_Chain.h"

int main() {
    setlocale(0, "rus");
    Hash_Chain universityTable;

    universityTable.insert(1990, "����������� A", "����");
    universityTable.insert(2005, "����������� B", "����");
    universityTable.insert(1985, "����������� C", "����");

    cout << "����������� ��� �������:" << endl;
    universityTable.display();

    cout << "����� ������������, ���������� � 2005 ����:" << endl;
    universityTable.search(2005);

    cout << "����� ������������, ���������� � 2005 ����:" << endl;
    universityTable.search(1999);

    return 0;
}