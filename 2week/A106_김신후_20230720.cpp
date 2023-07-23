#include <iostream>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        vector<bool> alphabet(26, false);
        for (char c : S) {
            if ('A' <= c && c <= 'Z') {
                alphabet[c - 'A'] = true;
            }
        }

        int asciiSum = 0;

        for (int i = 0; i < 26; i++) {
            if (!alphabet[i]) {
                asciiSum += ('A' + i);
            }
        }

        cout << asciiSum << endl;
    }

    return 0;
}
