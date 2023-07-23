/*
문제
79를 영어로 읽되 숫자 단위로 하나씩 읽는다면 "seven nine"이 된다. 80은 마찬가지로 "eight zero"라고 읽는다. 79는 80보다 작지만, 영어로 숫자 하나씩 읽는다면 "eight zero"가 "seven nine"보다 사전순으로 먼저 온다.

문제는 정수 M, N(1 ≤ M ≤ N ≤ 99)이 주어지면 M 이상 N 이하의 정수를 숫자 하나씩 읽었을 때를 기준으로 사전순으로 정렬하여 출력하는 것이다.

입력
첫째 줄에 M과 N이 주어진다.

출력
M 이상 N 이하의 정수를 문제 조건에 맞게 정렬하여 한 줄에 10개씩 출력한다.

예제 입력 1 
8 28
예제 출력 1 
8 9 18 15 14 19 11 17 16 13
12 10 28 25 24 21 27 26 23 22
20
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// abcdefghijklmnopqrstu
// 8 < 5 < 4 < 9 < 1 < 7 < 6 < 3 < 2
int order(int n){
    switch(n){
        case 1: return 5;
        case 2: return 9;
        case 3: return 8;
        case 4: return 3;
        case 5: return 2;
        case 6: return 7;
        case 7: return 6;
        case 8: return 1;
        case 9: return 4;
    }
}

// 비교 함수
bool cmp(const int& a, const int& b) {
    int tempA = a, tempB = b;
    
    // 각 숫자를 역순으로 비교하여 사전순으로 정렬
    while (tempA > 0 && tempB > 0) {
        int digitA = tempA % 10;
        int digitB = tempB % 10;

        // 각 숫자의 읽기 순서로 비교
        if (order(digitA) != order(digitB))
            return order(digitA) < order(digitB);
        
        tempA /= 10;
        tempB /= 10;
    }

    return a < b; // 같은 숫자이면 작은 숫자가 먼저 옴
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> ll;
    for(int i = N; i <= M; i++){
        ll.push_back(i);
    }
    sort(ll.begin(), ll.end(), cmp);

    int count = 0;
    for (int num : ll) {
        cout << num << " ";
        count++;
        if (count % 10 == 0)
            cout << "\n";
    }

    return 0;
}
