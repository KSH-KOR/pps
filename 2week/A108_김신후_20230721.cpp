#include <iostream>
using namespace std;

int reverseNumber(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

bool isSymmetric(int n) {
    int reversed = reverseNumber(n);
    return n + reversed == reverseNumber(n + reversed);
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        if (isSymmetric(N)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
