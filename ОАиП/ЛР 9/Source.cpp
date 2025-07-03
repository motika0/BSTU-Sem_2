#include <iostream>
using namespace std;

double f(double x, int n) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return x;
    }
    else {
        return (x * x / n / (n - 1) * f(x, n - 2));
    }
}

int main() {
    setlocale(0, "rus");
    double x;
    int n;    
    cout << "������� �������� x" << endl;
    cin >> x;
    cout << "������� �������� n" << endl;
    cin >> n;
    double result = f(x, n);

    cout << "�������� f(" << x << ", " << n << ") = " << result << endl;

    return 0;
}