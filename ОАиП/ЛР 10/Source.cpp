#include <iostream>
#include <string>
using namespace std;

// Структура для хранения данных о квитанции
struct Kv {
    string nameGroup;
    string Brand;
    string Date;
    string fixTime;
    string feel;
};

// Узел бинарного дерева
struct TreeNode {
    Kv data;
    TreeNode* left;
    TreeNode* right;
};

// Вставка новой квитанции
TreeNode* insertKv(TreeNode* node, const Kv& kv) {
    if (!node) {
        return new TreeNode{ kv, nullptr, nullptr };
    }
    if (kv.Date < node->data.Date) {
        node->left = insertKv(node->left, kv);
    }
    else {
        node->right = insertKv(node->right, kv);
    }
    return node;
}

// Поиск квитанции по дате
Kv* findKv(TreeNode* node, const string& date) {
    if (!node) {
        return nullptr;
    }
    if (node->data.Date == date) {
        return &node->data;
    }
    else if (date < node->data.Date) {
        return findKv(node->left, date);
    }
    else {
        return findKv(node->right, date);
    }
}

int main() {
    setlocale(0, "rus");
    TreeNode* root = nullptr;

    Kv kv1{ "Телевизоры", "Samsung", "2024-06-03", "14:00", "Отремонтирован"};
    root = insertKv(root, kv1);
    Kv kv2{ "Телевизоры", "LG", "2024-05-05", "14:00","Ремонтируется"};
    root = insertKv(root, kv2);

    string searchDate;
    cout << "Здравстувуйте, это поиск по квитанции. Введите дату по примеру: 2024-04-03" << endl;
    cin >> searchDate;
    Kv* foundKv = findKv(root, searchDate);
    if (foundKv) {
        cout << "Состояние объекта: " << foundKv->feel << endl;
    }
    else {
        cout << "Квитанция не найдена." << endl;
    }

    return 0;
}
/*#include <iostream>: Подключение стандартной библиотеки ввода/вывода для работы с потоками ввода/вывода.
   
2. #include <string>: Подключение стандартной библиотеки для работы со строками.

3. using namespace std;: Использование пространства имен std, чтобы избежать необходимости писать std:: перед стандартными идентификаторами.

4. struct Kv { ... };: Определение структуры Kv, которая содержит данные о квитанции (название группы продуктов, бренд, дата, время ремонта).

5. struct TreeNode { ... };: Определение структуры TreeNode, которая представляет узел бинарного дерева. Узел содержит данные о квитанции типа Kv, указатели на левого и правого потомка.

6. TreeNode* insertKv(TreeNode* node, const Kv& kv) { ... }: Функция для вставки новой квитанции в бинарное дерево. Если узел node пустой, создается новый узел с данными kv. Иначе происходит рекурсивный вызов функции для определения места вставки.

7. Kv* findKv(TreeNode* node, const string& date) { ... }: Функция для поиска квитанции по дате в бинарном дереве. Если узел node пустой, возвращается nullptr. Если дата совпадает с датой узла, возвращаются данные этого узла. Иначе происходит рекурсивный вызов функции для поиска в левом или правом поддереве.

8. int main() { ... }: Главная функция программы.

9. setlocale(0, "rus");: Установка локали для корректного отображения русского текста в консоли.

10. TreeNode* root = nullptr;: Объявление указателя на корень бинарного дерева и его инициализация как nullptr.

11. Создание объектов квитанций kv1 и kv2 с заполнением данными о них.

12. Ввод пользователем даты для поиска квитанции.

13. Поиск квитанции по введенной дате с помощью функции findKv.

14. Вывод результата поиска: если квитанция найдена, выводится бренд, иначе выводится сообщение об отсутствии квитанции.

15. return 0;: Завершение работы программы с возвратом нулевого значения.*/