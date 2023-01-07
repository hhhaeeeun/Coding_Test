#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> home;
vector<pair<int, int>>chicken;
queue<vector<int>> q;

void combi(int start, vector<int> b) {
	if (b.size() == m) {
		q.push(b);
		return;
	}
	for (int i = start + 1; i < chicken.size(); i++) {
		b.push_back(i);
		combi(i, b);
		b.pop_back();
	}
	return;
}
int distance_to_chicken(vector<int> c_pick) {
	int ret = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int home_min = 2147483647;
		for (int j = 0; j < c_pick.size(); j++)
		{
			int now = abs(home[i].first - chicken[c_pick[j]].first) + abs(home[i].second - chicken[c_pick[j]].second);
			if (now < home_min) home_min = now;
		}
		ret += home_min;
	}
	return ret;
}
int distance_to_chicken() {
	int ret = 0;
	for (int i = 0; i < home.size(); i++)
	{
		int home_min = 2147483647;
		for (int j = 0; j < chicken.size(); j++)
		{
			int now = abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second);
			if (now < home_min) home_min = now;
		}
		ret += home_min;
	}
	return ret;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int num = 0;
			cin >> num;
			if (num == 1)
			{
				home.push_back({ i,j });
			}
			if (num == 2)
			{
				chicken.push_back({ i,j });
			}
		}
	}
	int chicken_min = 2147483647;
	if (m >= chicken.size())
	{
		cout << distance_to_chicken() << "\n";
		return 0;
	}
	else
	{
		vector<int> index;
		combi(-1, index);

		while (q.size())
		{
			index = q.front(); q.pop();
			int now_min = distance_to_chicken(index);
			if (now_min < chicken_min) {
				chicken_min = now_min;
			}
		}
	}
	cout << chicken_min << "\n";
	return 0;
}

