#include<bits/stdc++.h>
using namespace std;
int n;
int A[21][21];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
const int INF = 987654321;
int ret = 0;
struct BOARD {
	int map[21][21];

	int find_max() {
		int m_max = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
			{
				m_max = max(m_max, map[i][j]);
			}
		}
		return m_max;
	}

	void rotate() {
		int temp[21][21] = { 0, };
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < n; x++)
			{
				temp[y][x] = map[n - 1 - x][y];
			}
		}
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				map[y][x] = temp[y][x];
			}
		}
	}

	void up() {
		int temp[21][21]={0, };

		for (int x = 0; x < n; x++)
		{
			int flag = 0; int target = -1;
			for (int y = 0; y< n; y++)
			{
				if (map[y][x] == 0)continue;
				
				if (flag == 1 && temp[target][x] == map[y][x]){
					temp[target][x] *= 2; flag = 0;				
				}
				else	{
					temp[++target][x] = map[y][x]; flag = 1;
				}
			}
		}
		for (int y = 0; y < n; ++y) {
			for (int x = 0; x < n; ++x) {
				map[y][x] = temp[y][x];
			}
		}
		return;
	}

};
void dfs(BOARD B, int count) {
	if (count == 5) {
		int m_max = B.find_max();
		ret = max(ret, m_max);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		BOARD next = B;
		next.up();		
		dfs(next, count + 1);
		B.rotate();
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	BOARD B;
	cin >> n ;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> B.map[i][j];
	}

	dfs(B, 0);
	cout << ret << endl;

	return 0;
}

