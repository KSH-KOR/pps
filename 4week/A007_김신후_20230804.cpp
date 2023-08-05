// 조건문을 (isAsc || isDes)로 변경하여 불필요한 반복문을 줄였다.
// 함수 내에서 반환 값이 명확하게 설정되도록 return 문을 추가하였다.
#include <iostream>
#include <cstring>
using namespace std;

int solution(const char* s) {
    if ((s[0] != '1') && (s[0] != '8')) return 2;
    bool isAsc = true;
    bool isDes = true;
    char count = '1';
    int length = strlen(s);
    for (int i = 0; i < length; i++) {
        if (s[i] == ' ') continue;
        if (s[i] != count) isAsc = false;
        if (s[i] != '9' - count + '0') isDes = false;
        if (!(isAsc || isDes)) return 2;
        count++;
    }
    if (isAsc) return 0;
    if (isDes) return 1;
    return 2;
}

int main() {
    char s[16];
    cin.getline(s, 16);
    switch (solution(s)) {
    case 0:
        cout << "ascending";
        break;
    case 1:
        cout << "descending";
        break;
    default:
        cout << "mixed";
        break;
    }
}

/*
#include <string>
#include <iostream>
using namespace std;

int solution(char* s) {
    if ((s[0] != '1') && (s[0] != '8')) return 2;
    bool isAsc = true;
    bool isDes = true;
    char count = '1';
    for (int i = 0; i < sizeof(s); i++) {
        if (s[i] == ' ') continue;
        if (s[i] != count) isAsc = false;
        if (s[i] != '9' - count + 48) isDes = false;
        if (!(isAsc + isDes)) return 2;
        count++;
    }
    if (isAsc) return 0;
    if (isDes) return 1;
}

int main() {
    char s[16];
    cin.getline(s, 16);
    switch (solution(s)) {
    case 0:
        cout << "ascending";
        break;
    case 1:
        cout << "descending";
        break;
    default:
        cout << "mixed";
        break;
    }
}
*/