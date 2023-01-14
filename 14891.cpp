#include<bits/stdc++.h>
using namespace std;
int n;
int A[5][9];
int m[100][100];
int ret;
//시계, 반시계
int m_clock[2][8] = { {7,0,1,2,3,4,5,6}, {1,2,3,4,5,6,7,0} };
//왼 오
int d[2] = {-1, 1};

int visited[5];
void m_dd(int num, int dir)
{
	//dir == 1 시계방향
	//dir == 2 반시계 방향
	int tem[9] = { 0, };
	for (int i = 0; i < 8; i++)
	{
		tem[i] = A[num][m_clock[dir][i]];
	}
	for (int i = 0; i < 8; i++)
	{
		A[num][i] = tem[i];
	}	
}
void dd(int num, int dir) {
	visited[num] = 1;

	for (int i = 0; i < 2; i++) {
		int nx = num + d[i];
		if (nx < 1 || nx > 4)continue;
		if (visited[nx] == 1)continue;
		if (i == 0)//왼쪽
		{
			if (A[num][6] != A[nx][2])
			{
				dd(nx, (dir + 1) % 2);
			}
		}
		if (i == 1)//오른쪽
		{
			if (A[num][2] != A[nx][6])
			{
				dd(nx, (dir + 1) % 2);
			}
		}
	}
	m_dd(num, dir);
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for (int i = 1; i < 5; i++) {
		string s = "";
		cin >> s;
		for (int j = 0; j < 8; j++) {
			A[i][j] = s[j] - '0';
		}
	}
	cin >> n;
	for (int i = 0; i < n; i++)
	{

		int b = 0;
		cin >> m[i][0] >> b;
		if (b == -1) m[i][1] = 1;
		if (b == 1) m[i][1] = 0;
	}

	for (int i = 0; i < n; i++)
	{
		memset(visited, 0, sizeof(visited));
		dd(m[i][0], m[i][1]);
	}


	int w[5] = {0,1,2,4,8};

	for (int i = 1; i < 5; i++)
		ret += (A[i][0]) * w[i];
	cout << ret << "\n";
	return 0;
}