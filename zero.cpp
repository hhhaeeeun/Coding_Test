#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<tuple>
#include<climits>
using namespace std;

int A[4][4001];
int n;
int a[16000001];
int b[16000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("zero.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> A[j][i];
		}
	}
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			a[idx++] = A[1][i] + A[0][j];
		}
	}
	idx = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			b[idx++] = A[2][i] + A[3][j];
		}
	}
	sort(a, a + (n * n));
	sort(b, b + (n * n));
	int ret = 0;
	for (int i = 0; i < n * n; i++) {
		int target = a[i] * (-1);
		int start = 0;
		int end = n * n;
		while (start<=end) {
			int mid = (start + end) / 2;
			if (b[mid] < target) {
				start = mid + 1;
			}
			else if (b[mid] > target) {
				end = mid - 1;
			}
			else {
				ret++;
				int t_idx = mid - 1;
				while (b[t_idx] == target) {
					ret++;
					t_idx--;
				}
				t_idx = mid + 1;
				while (b[t_idx] == target) {
					ret++;
					t_idx++;
				}
				break;
			}
		}
	}
	cout << ret;
	return 0;
}