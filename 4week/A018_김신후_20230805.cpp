//입력 받는 부분에서 중복되는 코드를 하나의 반복문으로 합쳐서 더 간단하게 작성하였다.
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> b(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int answer = 0;
    for (int i = 0; i < N; i++) {
        answer += (a[i] * b[N - i - 1]);
    }

    cout << answer;
}

/*#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int main() {
	int N;
	vector<int> a;
	vector<int> b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		a.push_back(t);
	}
	for (int i = 0; i < N; i++) {
		int t;
		cin >> t;
		b.push_back(t);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int answer = 0;
	for (int i = 0; i < N; i++) {
		answer += (a[i] * b[N-i-1]);
	}
	cout << answer;
}