#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string S;
    cin >> S;
    
    int N = S.length();
    vector<string> suffixes;
    
    // 모든 접미사 생성
    for (int i = 0; i < N; i++) {
        suffixes.push_back(S.substr(i));
    }
    
    // 접미사를 사전순으로 정렬
    sort(suffixes.begin(), suffixes.end());
    
    // 정렬된 접미사 출력
    for (const string& suffix : suffixes) {
        cout << suffix << '\n';
    }
    
    return 0;
}
