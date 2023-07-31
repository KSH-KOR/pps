/*
문제
수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.

예제 입력 1 
5
1
3
8
-2
2
예제 출력 1 
2
2
1
10
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    double sum = 0;
    for (int i = 0; i < N; i++) {
        sum += numbers[i];
    }
    double arithmetic_mean = sum / N;

    int median = numbers[N / 2];

    int mode = numbers[0];
    int max_frequency = 1;
    int current_frequency = 1;
    for (int i = 1; i < N; i++) {
        if (numbers[i] == numbers[i - 1]) {
            current_frequency++;
        } else {
            current_frequency = 1;
        }

        if (current_frequency > max_frequency) {
            max_frequency = current_frequency;
            mode = numbers[i];
        }
    }

    int range = numbers[N - 1] - numbers[0];

    cout << round(arithmetic_mean) << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << range << endl;

    return 0;
}

