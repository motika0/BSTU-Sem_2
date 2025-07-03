#include "Hash_Chain.h"

int main() {
    setlocale(0, "rus");
    Hash_Chain universityTable;

    universityTable.insert(1990, "Университет A", "Миша");
    universityTable.insert(2005, "Университет B", "Даша");
    universityTable.insert(1985, "Университет C", "Ваня");

    cout << "Отображение хэш таблицы:" << endl;
    universityTable.display();

    cout << "Поиск университета, созданного в 2005 году:" << endl;
    universityTable.search(2005);

    cout << "Поиск университета, созданного в 2005 году:" << endl;
    universityTable.search(1999);

    return 0;
}