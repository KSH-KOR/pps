#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    int sum = 0;
    int num = 1; 
    int count = 1; 
    for (int i = 1; i <= B; i++) {
        if (i >= A) {
            sum += num;
        }

        count--;
        if (count == 0) {
            num++; 
            count = num;
        }
    }

    cout << sum << endl;
    return 0;
}
