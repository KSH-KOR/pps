#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int n = 1;
    while (n * (n + 1) / 2 < X) {
        n++;
    }

    int numerator, denominator;
    int diff = n * (n + 1) / 2 - X;
    if (n % 2 == 0) {
        numerator = 1 + diff;
        denominator = n - diff;
    } else {
        numerator = n - diff;
        denominator = 1 + diff;
    }

    cout << denominator << "/" << numerator << endl;
    return 0;
}
