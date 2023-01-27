#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
int n, m, t;
int a[51][51];
vector<pair<int, int>> mg;
vector<int> clean;
void mg_diff() {
	int nmg[51][51] = { 0, };
	vector<pair<int, int>> newmg;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] < 1)continue;
			int temp = a[i][j] / 5;
			if (temp == 0)
			{
				nmg[i][j] += a[i][j];
				continue;
			}
			int num = 0;
			for (int k = 0; k < 4; k++) {
				int ny = i + dy[k];
				int nx = j + dx[k];
				if (ny < 0 || ny >= n || nx < 0 || nx >= m)continue;
				if (a[ny][nx] == -1) continue;
				nmg[ny][nx] += temp;
				++num;
			}
			nmg[i][j] += a[i][j] - temp * num;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (nmg[i][j] > 0)
				ans += nmg[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (nmg[i][j] > 0)
				a[i][j] = nmg[i][j];
		}
	}
	return;
}
void cleaning_mg(int sy, int sx) {
	int nmg[51][51] = { 0, };
	for (int i = 1; i < m; i++) {
		nmg[sy][i] = a[sy][i - 1];
		a[sy][i - 1] = 0;
	}
	for (int i = sy-1; i >= 0; --i) {
		nmg[i][m-1] = a[i+1][m-1];
		a[i + 1][m - 1] = 0;
	}
	for (int i = m-2; i >= 0; --i) {
		nmg[0][i] = a[0][i+1];
		a[0][i + 1] = 0;
	}
	for (int i = 1; i <=sy; ++i) {
		nmg[i][0] = a[i-1][0];
		a[i - 1][0] = 0;
	}


	for (int i = 1; i < m; i++) {
		nmg[sy+1][i] = a[sy+1][i - 1];
		a[sy + 1][i - 1] = 0;
	}
	for (int i = sy + 2; i <n; ++i) {
		nmg[i][m - 1] = a[i - 1][m - 1];
		a[i - 1][m - 1] = 0;
	}
	for (int i = m - 2; i >= 0; --i) {
		nmg[n-1][i] = a[n-1][i + 1];
		a[n - 1][i + 1] = 0;
	}
	for (int i = n-2; i >= sy+1; --i) {
		nmg[i][0] = a[i + 1][0];
		a[i + 1][0] = 0;
	}



	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == -1) continue;
			if (nmg[i][j] == -1)
				a[i][j] = 0;
			else if (nmg[i][j] >0)
				a[i][j] = nmg[i][j];
		}
	}


}
int main(int argc, char** argv)
{
	freopen("17144.txt", "r", stdin);
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1)
				clean.push_back(i);
		}
	}
	int aa = 0;
	int bb= 0;
	int ret =188;
	int dd = 0;
	for (int i = 0; i < t; i++) {
		
		mg_diff();
		aa = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] > 0)
					aa += a[i][j];
			}
		}

		cleaning_mg(clean[0], 0);
		if (a[clean[0]][0])
			ret -= a[clean[0]][0];
		if (a[clean[1]][0])
			ret -= a[clean[1]][0];
		a[clean[0]][0] = -1;
		a[clean[1]][0] = -1;
		bb = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] > 0)
					bb += a[i][j];
			}
		}
		
	}


	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(a[i][j]>0)
				ans += a[i][j];
		}
	}

	cout << ans;
	return 0;
}