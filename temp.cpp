#if 0
#include<bits/stdc++.h>
using namespace std;
int n, m;
int A[6][6];
//��, ��, �Ʒ�, ��
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
const int INF = 987654321;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++)
			cin >> A[i][j];
	}
	

	return 0;
}
#endif

//int visited[50][50]
//memset(visited, 0, sizeof(visited));
// memset(�迭 �̸�, �ʱ�ȭ ��, �迭 ũ��);
//fill(&visited[0][0], &visited[49][50], 0);
//fill(&arr[0][0], &arr[ROW - 1][COL], value)
//fill(���� ��ġ, ������ ��ġ + 1, �ʱ�ȭ ��);
//fill(v.begin(), v.end(), make_pair(0, 0)); // vector<pair<int,int>>�϶�..
//fill(&visited[0][0], &visited[0][0] + 54 * 54, 0);
//for(int i : { 0b00001, 0b00011, 0b00111, 0b01111, 0b11111} )


#if 0
void bfs(int sy, int sx)
{
	visited[sy][sx] = 1;
	queue<pair<int, int>> q;
	q.push({ sy,sx });
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny,nx });
		}
	}
}

void dfs(int y, int x)
{
	visited[y][x] = 1;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= n || nx < 0 || nx >= n)continue;
		if (visited[ny][nx] == 0)
		{
			dfs(ny, nx);
		}
	}
}
#endif

#if 0
#include<bits/stdc++.h>
using namespace std;
void printV(vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}
int main() {
	int a[3] = { 1, 1, 3 };
	vector<int> v;
	for (int i = 0; i < 3; i++)
		v.push_back(a[i]);
	//1, 2, 3���� ������������ ������ �̽��ϴ�.
	do {
		printV(v);
	} while (next_permutation(v.begin(), v.end()));
	cout << "-------------" << '\n';
	v.clear();
	for (int i = 2; i >= 0; i--)
		v.push_back(a[i]);
	//3, 2, 1���� ������������ ������ �̽��ϴ�.
	do {
		printV(v);
	} while (prev_permutation(v.begin(), v.end()));
	return 0;
}
#endif

#if 0
#include <bits/stdc++.h>
using namespace std;
int n = 5, k = 3, a[5] = { 1, 2, 3, 4, 5 };
void print(vector<int> b) {
	for (int i : b)cout << i << " ";
	cout << '\n';
}
void combi(int start, vector<int> b) {
	if (b.size() == k) {
		print(b);
		return;
	}
	for (int i = start + 1; i < n; i++) {
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
}
int main() {
	vector<int> b;
	combi(-1, b);
	return 0;
}
#endif

#if 0
#include <iostream>
#include <algorithm>

#define MAX_NUM 1000

using namespace std;

int n;
int num[MAX_NUM][MAX_NUM];
int dp[MAX_NUM][MAX_NUM];

void Initialize() {
	// �������� ��� dp[0][0] = num[0][0]���� �ʱⰪ�� �������ݴϴ�
	dp[0][0] = num[0][0];

	// ������ ���� �ʱⰪ�� �������ݴϴ�.
	for (int i = 1; i < n; i++)
		dp[i][0] = dp[i - 1][0] + num[i][0];

	// �ֻ�� ���� �ʱⰪ�� �������ݴϴ�.
	for (int j = 1; j < n; j++)
		dp[0][j] = dp[0][j - 1] + num[0][j];
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> num[i][j];

	// �ʱⰪ ����
	Initialize();

	// Ž���ϴ� ��ġ�� ���� ���� ���� �� �߿� ū ����
	// �ش� ��ġ�� ���ڸ� �����ݴϴ�. 
	for (int i = 1; i < n; i++)
		for (int j = 1; j < n; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + num[i][j];


	cout << dp[n - 1][n - 1];

	return 0;
}

#endif
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int ret, n;
int A[51][51];
//��, ��, �Ʒ�, ��
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0,-1,0,1 };
int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> A[i][j];
			}
		}



		cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
#endif

#if 0

#include<bits/stdc++.h>
using namespace std;
int dp[1004][2][34], n, m, b[1004];

int go(int idx, int tree, int cnt) {
	//�������
	if (cnt < 0) return -1e9;
	if (idx == n) return cnt == 0 ? 0 : -1e9;
	// �޸������̼�
	int& ret = dp[idx][tree][cnt];
	if (~ret) return ret;
	//����
	return ret = max(go(idx + 1, tree ^ 1, cnt - 1), go(idx + 1, tree, cnt)) + (tree == b[idx] - 1);
}

int main() {
	// �ʱ�ȭ
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> b[i];
	cout << max(go(0, 1, m - 1), go(0, 0, m)) << '\n';
	return 0;
}
#endif

#if 0
#include <bits/stdc++.h>
using namespace std;
// ��Ʈ����ŷ + DP
const int IMPOSSIBLE = 1987654321;
int N, W[16][16];
// dp[k][state] : k��° ����, state: �湮�ߴ� ���õ��� 2�������� ǥ��.
int dp[16][1 << 16];

int TSP(int current, int visited) {
	int& ret = dp[current][visited];
	if (ret != -1)
		return ret;
	// ��� ���� �湮�ߴ°�
	if (visited == (1 << N) - 1) {
		// current -> 0 �̵� �������� 
		if (W[current][0] != 0)
			return W[current][0];
		// �������� ������
		return IMPOSSIBLE;

	}
	ret = IMPOSSIBLE;
	for (int i = 0; i < N; ++i) {
		// �湮�߰ų� || current -> i �� ���� ���ų�
		if (visited & (1 << i) || W[current][i] == 0)
			continue;
		ret = min(ret, TSP(i, visited | (1 << i)) + W[current][i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cin >> W[i][j];
	}
	memset(dp, -1, sizeof(dp));
	cout << TSP(0, 1) << '\n';

	return 0;
}

#endif
#if 0
#include <bits/stdc++.h>
using namespace std;
const int n = 4;
string a[4] = { "���", "����", "����", "��" };
void go(int num) {
	string ret = "";
	for (int i = 0; i < 4; i++) {
		if (num & (1 << i)) ret += a[i] + " ";
	}
	cout << ret << '\n';
	return;
}
int main() {
	for (int i = 1; i < n; i++) {
		go(1 | (1 << i));
	}
	return 0;
}
/*
��� ����
��� ����
��� ��
*/
#endif
#if 0
#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;

int n, m;
int a[50][50];
//��, ��, �Ʒ�, ��
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0, -1, 0, 1 };
int dp[51][51][51];

bool is_in(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m)
		return false;
	if (a[y][x] == 0)
		return false;
	return true;
}
void init() {
	fill(&dp[0][0][0], &dp[50][51][51], INT_MIN);
	dp[0][0][0] = 0;
	return;
}


int go(int r) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) continue;
			int jump = a[i][j];

			for (int k = 0; k < 4; k++) {
				int ny = i + jump * dy[k];
				int nx = j + jump * dx[k];
				if (!is_in(ny, nx)) continue;
				dp[r + 1][ny][nx] = max(dp[r + 1][ny][nx], dp[r][i][j] + 1);
				ret = max(ret, dp[r + 1][ny][nx]);
			}
		}
	}
	return ret;
}
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s = "";
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') a[i][j] = 0;
			else a[i][j] = s[j] - '0';
		}
	}
	init();
	int now_ret = 0;
	bool is_inf = true;
	for (int i = 0; i < 250; i++) {
		int tmp = go(i);
		if (tmp == 0)
		{
			++now_ret;
			is_inf = false;
			break;
		}
		else
			now_ret = tmp;
	}

	if (is_inf == true)
		cout << "-1\n";
	else
		cout << now_ret << "\n";

	return 0;

}

#endif


#if 0
#include<algorithm>
#include<iostream>
#include<climits>
using namespace std;

int n, m;
int a[50][50];
//��, ��, �Ʒ�, ��
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0, -1, 0, 1 };
int dp[51][51][51];

bool is_in(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= m)
		return false;
	if (a[y][x] == 0)
		return false;
	return true;
}
void init() {
	fill(&dp[0][0][0], &dp[50][51][51], INT_MIN);
	dp[0][0][0] = 0;
	return;
}


int go(int r) {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 0) continue;
			int jump = a[i][j];

			for (int k = 0; k < 4; k++) {
				int ny = i + jump * dy[k];
				int nx = j + jump * dx[k];
				if (!is_in(ny, nx)) continue;
				dp[r + 1][ny][nx] = max(dp[r + 1][ny][nx], dp[r][i][j] + 1);
				ret = max(ret, dp[r + 1][ny][nx]);
			}
		}
	}
	return ret;
}
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s = "";
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'H') a[i][j] = 0;
			else a[i][j] = s[j] - '0';
		}
	}
	init();
	int now_ret = 0;
	bool is_inf = true;
	for (int i = 0; i < 250; i++) {
		int tmp = go(i);
		if (tmp == 0)
		{
			++now_ret;
			is_inf = false;
			break;
		}
		else
			now_ret = tmp;
	}

	if (is_inf == true)
		cout << "-1\n";
	else
		cout << now_ret << "\n";

	return 0;

}

#endif
