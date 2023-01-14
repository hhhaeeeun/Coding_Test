#if 0
#include<bits/stdc++.h>
using namespace std;
int n, m,h;
int A[50][50];

//아래, 오, 왼
bool go_go();
void delete_line(int y, int x);
void push_line(int y, int x);
bool push_oneline();
bool push_twoline();

//줄을 하나 추가한상태에서 줄을 두개 추가해본다
bool push_twoline() {
	bool ret = false;
	for (int i = 1; i < h + 1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (A[i][j] == 0 && A[i][j + 1] == 0)
			{
				push_line(i, j);
				ret = push_oneline();
				if (ret == true)
				{
					cout << i << " " << j << endl;
					return ret;
				}
				delete_line(i, j);
			}

		}
	}
	return ret;
}
//줄을 하나 추가한 상태에서 줄을 또 추가 해본다
bool push_oneline()
{
	bool ret = false;
	//push_oneline;
	for (int i = 1; i < h + 1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (A[i][j] == 0 && A[i][j + 1] == 0)
			{
				push_line(i, j);
				ret = go_go();
				if (ret == true)
				{
					cout << i << " "<<j << endl;
					return ret;
				}
				delete_line(i, j);
			}
		}
	}
	return ret;
}

void push_line(int y, int x)
{
	A[y][x] = 1;
	A[y][x + 1] = -1;
}
void delete_line(int y, int x)
{
	A[y][x] = 0;
	A[y][x + 1] = 0;
}
bool go_go() {
	for (int nx = 1; nx < n + 1; nx++)
	{
		int index = nx;
		for (int ny = 1; ny < h + 1; ny++)
		{
			index += A[ny][index];
		}
		if (index != nx) return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m>>h;
	for (int i = 0; i < m; i++) {
		int y = 0; int x = 0;
		cin >> y >> x;
		push_line(y, x);
	}
	if (go_go())
	{
		cout << "0\n";
		return 0;
	}
	bool ret = false;
	//push_oneline;
	for (int i = 1; i < h+1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (A[i][j] == 0 && A[i][j+1] == 0)
			{
				push_line(i, j);
				ret = go_go();
				delete_line(i, j);
			}
			if (ret == true)
			{
				cout << "1\n";
				return 0;
			}
		}
	}
	for (int i = 1; i < h + 1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (A[i][j] == 0 && A[i][j + 1] == 0)
			{
				push_line(i, j);
				ret = push_oneline();
				delete_line(i, j);
			}
			if (ret == true)
			{
				cout << "2\n";
				return 0;
			}
		}
	}


	for (int i = 1; i < h + 1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (A[i][j] == 0 && A[i][j + 1] == 0)
			{
				push_line(i, j);
				ret = push_twoline();
				if (ret == true)
				{
					cout << i << " " << j << endl;
					cout << "3\n";
					return 0;
				}
				delete_line(i, j);
			}

		}
	}
	cout << "-1\n";
	return 0;
}
#endif



#include<bits/stdc++.h>
using namespace std;
int n, m, h;
int A[50][50];

//아래, 오, 왼
bool go_go();
void delete_line(int y, int x);
void push_line(int y, int x);


void push_line(int y, int x)
{
	A[y][x] = 1;
	A[y][x + 1] = -1;
}
void delete_line(int y, int x)
{
	A[y][x] = 0;
	A[y][x + 1] = 0;
}
bool go_go() {
	for (int nx = 1; nx < n + 1; nx++)
	{
		int index = nx;
		for (int ny = 1; ny < h + 1; ny++)
		{
			index += A[ny][index];
		}
		if (index != nx) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		int y = 0; int x = 0;
		cin >> y >> x;
		push_line(y, x);
	}
	if (go_go())
	{
		cout << "0\n";
		return 0;
	}

	vector<pair<int, int>> v;
	for (int i = 1; i < h + 1; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (A[i][j] == 0 && A[i][j + 1] == 0)
				v.push_back({ i, j });
		}
	}
	bool ret = false;
	for (int i = 0; i < v.size(); i++)
	{
		push_line(v[i].first, v[i].second);
		ret = go_go();
		delete_line(v[i].first, v[i].second);
		if (ret == true)
		{
			cout << "1\n";
			return 0;
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		push_line(v[i].first, v[i].second);

		for (int j = i + 1; j < v.size(); j++)
		{
			if (A[v[j].first][v[j].second] != 0 || A[v[j].first][v[j].second + 1] != 0)continue;
			push_line(v[j].first, v[j].second);
			ret = go_go();
			delete_line(v[j].first, v[j].second);
			if (ret == true)
			{
				cout << "2\n";
				return 0;
			}
		}
		delete_line(v[i].first, v[i].second);
	}

	for (int i = 0; i < v.size(); i++)
	{
		push_line(v[i].first, v[i].second);
		for (int j = i + 1; j < v.size(); j++)
		{
			if (A[v[j].first][v[j].second] != 0 || A[v[j].first][v[j].second + 1] != 0)continue;
			push_line(v[j].first, v[j].second);
			for (int k = j + 1; k < v.size(); k++)
			{
				if (A[v[k].first][v[k].second] != 0 || A[v[k].first][v[k].second + 1] != 0)continue;
				push_line(v[k].first, v[k].second);
				ret = go_go();
				delete_line(v[k].first, v[k].second);
				if (ret == true)
				{
					cout << "3\n";
					return 0;
				}
			}
			delete_line(v[j].first, v[j].second);
		}
		delete_line(v[i].first, v[i].second);
	}
		
	cout << "-1\n";
	return 0;
}