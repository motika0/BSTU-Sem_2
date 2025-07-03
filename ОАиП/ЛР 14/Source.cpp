#include <iostream>
#include <ctime> // ��� ��������� ��������� �����
using namespace std;

const int ARRAY_SIZE = 20; // ������ ��������

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// ������������� ����������
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; --i) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    setlocale(0, "rus");
    int A[ARRAY_SIZE];
    int B[ARRAY_SIZE];

    // ������������� ���������� ��������� �����
    srand(time(nullptr));

    // ���������� �������� ���������� �������
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        A[i] = rand() % 100; // ������������ �������� (0-99)
        B[i] = rand() % 100;
    }

    cout << "������� A � B �� ���������" << endl;

    cout << "������ A: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "������ B: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    int C[ARRAY_SIZE];
    int cIndex = 0; // ������ ��� ������� C

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (A[i] % 2 != 0) { // ���� ������� ��������
            C[cIndex++] = A[i];
        }
        if (B[i] % 2 == 0) { // ���� ������� ������
            C[cIndex++] = B[i];
        }
    }

    cout << "������ C �� ����������" << endl;

    cout << "������ C: ";
    for (int i = 0; i < cIndex; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    // ���������� ������� C ������������� �����������
    heapSort(C, cIndex);

    cout << "������ C ����� ������������� ����������:" << endl;
    for (int i = 0; i < cIndex; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    // ���������� ������� C ����������� �����������
    bubbleSort(C, cIndex);

    cout << "������ C ����� ���������� ���������:" << endl;
    for (int i = 0; i < cIndex; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}
