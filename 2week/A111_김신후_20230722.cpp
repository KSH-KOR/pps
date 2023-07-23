#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        int passengers = 1;
        for (int i = 0; i < k; i++) {
            passengers = 2 * passengers + 1;
        }

        cout << passengers << endl;
    }

    return 0;
}
