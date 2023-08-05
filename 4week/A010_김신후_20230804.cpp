//s.substr() 함수를 사용하여 반복문 내에서 문자열을 조각내어 처리하도록 변경하였다.
//압축된 문자열을 compressed에 쌓아가며 처리하고, 더 이상 비교하지 않고 바로 compressed에 추가하여 코드를 더 간결하게 만들었다.

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    if (s.empty()) return 0;
    int len = s.length();
    int minLen = len;

    for (int i = 1; i <= len / 2; i++) {
        string compressed;
        int count = 1;

        for (int j = 0; j < len; j += i) {
            string curr = s.substr(j, i);
            string next = s.substr(j + i, i);

            if (curr == next) {
                count++;
            } else {
                if (count > 1) {
                    compressed += to_string(count);
                    count = 1;
                }
                compressed += curr;
            }
        }

        if (count > 1) {
            compressed += to_string(count);
        }

        int tempLen = compressed.length();
        if (tempLen < minLen) minLen = tempLen;
    }
    return minLen;
}

/*
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    if (s.empty()) return 0;
    int len = s.length();
    string temp;
    string curr;
    string prev;
    int minLen = len;
    int tempLen;
    bool flag = false;
    int count=1;
    for (int i = 1; i <= len / 2; i++) {
        tempLen = len;
        prev = s.substr(0, i);
        for (int j = i; j < len; j += i) {
            curr = s.substr(j, i);
            if (prev.compare(curr) == 0) {
                count++;
                tempLen -= i;
            }
            else {
                if (count > 1) tempLen += to_string(count).length();
                count = 1;
            }
            prev = curr;
        }
        if (count > 1) tempLen += to_string(count).length();
        if (tempLen < minLen) minLen = tempLen;
        count = 1;
    }
    return minLen;
}
*/