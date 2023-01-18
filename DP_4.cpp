#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
struct pay {
	int start_day;
	int end_day;
	int val;
};
vector<pay>v;
int n;
int dp[1001];
bool compare(pay a, pay b) {
	if (a.start_day < b.start_day)
		return true;
	else if (a.start_day == b.start_day)
		return a.end_day < b.end_day;
	return false;
}
int main() {

	cin >> n;
	v.push_back(pay{ 0,0,0 });
	for (int i = 0; i < n; i++) {
		pay temp;
		cin >> temp.start_day >> temp.end_day >> temp.val;
		v.push_back(temp);
	}
	fill(dp, dp + 1001, -1);
	sort(v.begin(), v.end(), compare);
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if (v[i].start_day > v[j].end_day)
			{
				dp[i] = max(dp[i], dp[j] + v[i].val);
			}
		}
	}
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret = max(ret, dp[i]);
	}
	cout << ret;
}