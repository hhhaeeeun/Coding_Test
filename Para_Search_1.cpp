#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//cin >> n;
	n = 15;
	long long sum = 0;
	long long num = 0;
	while (sum < n) {
		num++;
		sum += num;
	}
    if (sum > n)
        cout << num - 1;
    else
        cout << num;
	return 0;
}

#if 0
#include <iostream>
#include <algorithm>

#define MAX_S 1000000000

using namespace std;

// ���� ����
long long s;

int main() {
    // �Է�:
    cin >> s;

    long long left = 1;                          // ���� ���� ���� ���� �����մϴ�.
    long long right = MAX_S;                     // ���� ū ���� ���� �����մϴ�.
    long long max_num = 0;                       // �ִ��̹Ƿ�, ���� �� �� �ִ� ������ �� ���� ������ �����մϴ�.

    while (left <= right) {                      // [left, right]�� ��ȿ�� �����̸� ��� �����մϴ�.
        long long mid = (left + right) / 2;      // ��� ��ġ�� �����մϴ�.
        if (mid * (mid + 1) / 2 <= s) {           // 1���� n������ ���� s���� ���ų� �۴ٸ�
            left = mid + 1;                      // �����ʿ� ������ �����ϴ� ���ڰ� �� ���� ���ɼ� ������ left�� �ٲ��ݴϴ�.
            max_num = max(max_num, mid);         // ���� �ĺ��� �� �ִ��� ��� �������ݴϴ�.
        }
        else
            right = mid - 1;                     // s���� ū ����� right�� �ٲ��ݴϴ�.
    }

    cout << max_num;                             // ������ �����ϴ� �ִ� n�� ���� ��ȯ�մϴ�.
    return 0;
}
#endif