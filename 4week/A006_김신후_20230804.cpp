// ps, ys를 각각 세어 같은 것을 확인하는 대신 count 하나의 변수로 두 이벤트의 발생 빈도를 체크 하도록하여, 변수를 하나 줄였다.
#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    int count = 0;

    for (char c : s) {
        if (c == 'p' || c == 'P') count++;
        else if (c == 'y' || c == 'Y') count--;
    }

    return count == 0;
}


/*
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int ps = 0, ys = 0;


    for (auto c : s) {
        if (c == 'p' || c == 'P') ps++;
        if (c == 'y' || c == 'Y') ys++;
    }

    return ps == ys;
}
*/