#include <iostream>
#include <string>
using namespace std;

// ��������� ��� �������� ������ � ���������
struct Kv {
    string nameGroup;
    string Brand;
    string Date;
    string fixTime;
    string feel;
};

// ���� ��������� ������
struct TreeNode {
    Kv data;
    TreeNode* left;
    TreeNode* right;
};

// ������� ����� ���������
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

// ����� ��������� �� ����
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

    Kv kv1{ "����������", "Samsung", "2024-06-03", "14:00", "��������������"};
    root = insertKv(root, kv1);
    Kv kv2{ "����������", "LG", "2024-05-05", "14:00","�������������"};
    root = insertKv(root, kv2);

    string searchDate;
    cout << "�������������, ��� ����� �� ���������. ������� ���� �� �������: 2024-04-03" << endl;
    cin >> searchDate;
    Kv* foundKv = findKv(root, searchDate);
    if (foundKv) {
        cout << "��������� �������: " << foundKv->feel << endl;
    }
    else {
        cout << "��������� �� �������." << endl;
    }

    return 0;
}
/*#include <iostream>: ����������� ����������� ���������� �����/������ ��� ������ � �������� �����/������.
   
2. #include <string>: ����������� ����������� ���������� ��� ������ �� ��������.

3. using namespace std;: ������������� ������������ ���� std, ����� �������� ������������� ������ std:: ����� ������������ ����������������.

4. struct Kv { ... };: ����������� ��������� Kv, ������� �������� ������ � ��������� (�������� ������ ���������, �����, ����, ����� �������).

5. struct TreeNode { ... };: ����������� ��������� TreeNode, ������� ������������ ���� ��������� ������. ���� �������� ������ � ��������� ���� Kv, ��������� �� ������ � ������� �������.

6. TreeNode* insertKv(TreeNode* node, const Kv& kv) { ... }: ������� ��� ������� ����� ��������� � �������� ������. ���� ���� node ������, ��������� ����� ���� � ������� kv. ����� ���������� ����������� ����� ������� ��� ����������� ����� �������.

7. Kv* findKv(TreeNode* node, const string& date) { ... }: ������� ��� ������ ��������� �� ���� � �������� ������. ���� ���� node ������, ������������ nullptr. ���� ���� ��������� � ����� ����, ������������ ������ ����� ����. ����� ���������� ����������� ����� ������� ��� ������ � ����� ��� ������ ���������.

8. int main() { ... }: ������� ������� ���������.

9. setlocale(0, "rus");: ��������� ������ ��� ����������� ����������� �������� ������ � �������.

10. TreeNode* root = nullptr;: ���������� ��������� �� ������ ��������� ������ � ��� ������������� ��� nullptr.

11. �������� �������� ��������� kv1 � kv2 � ����������� ������� � ���.

12. ���� ������������� ���� ��� ������ ���������.

13. ����� ��������� �� ��������� ���� � ������� ������� findKv.

14. ����� ���������� ������: ���� ��������� �������, ��������� �����, ����� ��������� ��������� �� ���������� ���������.

15. return 0;: ���������� ������ ��������� � ��������� �������� ��������.*/