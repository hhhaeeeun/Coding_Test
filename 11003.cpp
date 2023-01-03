#include<bits/stdc++.h>
using namespace std;
int n, m;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	cin >> m;

	deque<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		int now = 0;
		cin >> now;
		while (q.size() && (q.back().second > now)) {
			q.pop_back();
		}
		q.push_back({ i,now });
		
		if (q.front().first <= i - m)
			q.pop_front();
		cout << q.front().second << ' ';
	}
	return 0;
}
