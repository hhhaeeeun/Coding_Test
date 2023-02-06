#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int n;
int a[3][100002];
int La[3][100002];
int Ra[3][100002];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	freopen("LRT_2.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s = ""; cin >> s;
		if (s == "H") ++a[0][i];
		if (s == "S") ++a[1][i];
		if (s == "P") ++a[2][i];

		for (int k = 0; k < 3; k++)
			La[k][i] = La[k][i - 1] + a[k][i];
	}
	for (int i = n; i >= 1; --i) {
		for (int k = 0; k < 3; k++)
			Ra[k][i] = Ra[k][i + 1] + a[k][i];
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k < 3; k++){
			for (int u = 0; u < 3; u++){
				if (k == u)continue;
				ret = max(ret, La[k][i] + Ra[u][i] - a[k][i]);
			}
		}
	}
	cout << ret << '\n';
	return 0;
}

#if 0
#include <iostream>
#include <algorithm>

#define MAX_N 100000

using namespace std;

// ���� ����
int n;
char matches[MAX_N];

int L[MAX_N], R[MAX_N];
int ans;

int main() {
    // �Է�:
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> matches[i];

    char shapes[] = "PHS";

    // L �迭�� ä���ݴϴ�.
    // L[i] = 0������ i������ ������ ��縸 ���� ��
    //        �ִ�� �̱� �� �ִ� Ƚ��
    for (int s = 0; s < 3; s++) {
        char shape = shapes[s];
        int same_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (matches[i] == shape)
                same_cnt += 1;

            L[i] = max(L[i], same_cnt);
        }
    }

    // R �迭�� ä���ݴϴ�.
    // R[i] = i������ n - 1������ ������ ��縸 ���� ��
    //        �ִ�� �̱� �� �ִ� Ƚ��
    for (int s = 0; s < 3; s++) {
        char shape = shapes[s];
        int same_cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (matches[i] == shape)
                same_cnt += 1;

            R[i] = max(R[i], same_cnt);
        }
    }

    // �ش� ������ ������ �����ߴ� ���� ��
    // �ִ�� �̱�� Ƚ���� �������ݴϴ�.
    for (int i = 0; i < n - 1; i++)
        ans = max(ans, L[i] + R[i + 1]);

    cout << ans;
    return 0;
}
#endif
