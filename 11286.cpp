#include<bits/stdc++.h>
using namespace std;
int n, m;
struct compare {
	bool operator()(int a, int b)
	{
		int first_abs = abs(a);
		int second_abs = abs(b);


		if (first_abs == second_abs)
		{
			return a> b;
		}
		else if (first_abs > second_abs)
			return true;
		return false;
	}
	
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	priority_queue<int, vector<int>, compare> q;

	for (int i = 0; i < n; i++)
	{
		int now = 0;
		cin >> now;
		if (now)
		{
			q.push(now);
		}
		else
		{
			if(q.empty())
				cout <<0 << "\n";
			else {
				int num = q.top();
				q.pop();
				cout << num << "\n";
			}
		}
	}
	return 0;
}