#include <iostream>
using namespace std;

int main() {
    int M;
    cin >> M;

    int first_wheel_direction = 0; // 첫 번째 바퀴의 회전 방향 (시계 방향: 0, 반시계 방향: 1)
    long long first_wheel_speed = 1; // 첫 번째 바퀴의 분당 회전수

    for (int i = 0; i < M; i++) {
        int a, b, s;
        cin >> a >> b >> s;

        if (first_wheel_direction == 0) { // 첫 번째 바퀴의 회전 방향이 시계 방향인 경우
            first_wheel_speed *= b; // 첫 번째 바퀴를 1회전하면 두 번째 바퀴는 b회전하므로 분당 회전수에 b를 곱함
        } else { // 첫 번째 바퀴의 회전 방향이 반시계 방향인 경우
            first_wheel_speed *= a; // 첫 번째 바퀴를 1회전하면 두 번째 바퀴는 a회전하므로 분당 회전수에 a를 곱함
        }

        first_wheel_direction = (first_wheel_direction + s) % 2; // 첫 번째 바퀴의 회전 방향을 업데이트
    }

    cout << first_wheel_direction << " " << first_wheel_speed << endl;
    return 0;
}
