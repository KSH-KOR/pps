
//score 배열을 사용하지 않고, 입력을 받을 때 바로 평균과 학생 수를 계산하도록 변경하였다.
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int c, n, num, score;
    double avg, result;

    cin >> c;
    for (int i = 0; i < c; i++) {
        avg = 0;
        num = 0;
        cin >> n;

        for (int j = 0; j < n; j++) {
            cin >> score;
            avg += score;
        }
        avg /= n;
        for (int j = 0; j < n; j++) {
            cin >> score;
            if (score > avg)
                num++;
        }
        result = (double)num / n * 100;

        cout << fixed << setprecision(3) << result << "%" << endl;
    }
}


/*

#include <iostream>
using namespace std;

int main() {
	int c, n, num;
	int avg;
	int score[1000] = { 0 };
	double result;

	cin >> c;
	for (int i = 0; i < c; i++) {
		avg = 0;
		num = 0;
		cin >> n;

		for (int j = 0; j < n; j++) {
			cin >> score[j];
			avg = avg + score[j];
		}
		avg = avg / n;
		for (int j = 0; j < n; j++) {
			if (score[j] > avg)
				num++;
		}
		result = (double)num / n * 100;

		cout << fixed;
		cout.precision(3);
		cout << result << "%" << endl;
	}
}

*/