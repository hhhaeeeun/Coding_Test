#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
using namespace std;
int n, m, k;
class  ABC {
public:
	int a;
	int b;
	int c;
	ABC& operator+(ABC& ad) {
		a += ad.a;
		b += ad.b;
		c += ad.c;
		return *this;

	}
	ABC& operator-(ABC& ad) {
		a -= ad.a;
		b -= ad.b;
		c -= ad.c;
		return *this;
	}
};
ABC sum[1001][1001];
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);
	freopen("ps7.txt", "r", stdin);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		string s = "";
		cin >> s;
		for (int j = 1; j <= m; j++) {
			if (s[j-1] == 'a') {
				++sum[i][j].a;
			}
			if (s[j-1] == 'b') {
				++sum[i][j].b;
			}
			if (s[j-1] == 'c') {
				++sum[i][j].c;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			/*
			sum[i][j].a = sum[i - 1][j].a + sum[i][j - 1].a - sum[i - 1][j - 1].a + sum[i][j].a;
			sum[i][j].b = sum[i - 1][j].b + sum[i][j - 1].b - sum[i - 1][j - 1].b + sum[i][j].b;
			sum[i][j].c = sum[i - 1][j].c + sum[i][j - 1].c - sum[i - 1][j - 1].c + sum[i][j].c;
			*/
			sum[i][j] + sum[i - 1][j];
			sum[i][j] + sum[i][j - 1];
			sum[i][j] - sum[i - 1][j - 1];
		}
	}
	int ret = 0;
	for (int i = 0; i < k; i++) {
		int x1 = 0; int x2 = 0; int y1 = 0; int y2 = 0;
		cin >> x1 >> y1>> x2 >> y2;
		ABC temp;
		temp.a = sum[x2][y2].a - sum[x1 - 1][y2].a - sum[x2][y1 - 1].a + sum[x1 - 1][y1 - 1].a;
		temp.b = sum[x2][y2].b - sum[x1 - 1][y2].b - sum[x2][y1 - 1].b + sum[x1 - 1][y1 - 1].b;
		temp.c = sum[x2][y2].c - sum[x1 - 1][y2].c - sum[x2][y1 - 1].c + sum[x1 - 1][y1 - 1].c;

		cout << temp.a << ' ' << temp.b << ' ' << temp.c << '\n';
	}

	return 0;
}