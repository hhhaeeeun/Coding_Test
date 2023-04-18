#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<vector>
#include<iostream>
#include<climits>
#define ll long long
using namespace std;
struct Point { ll x, y, w; };
Point v[3001];
int n;
vector<pair<ll, ll> >nx, ny, yy[3001];
struct node {
	ll sum, lsum, rsum, msum;
};

void add(node& target, node& a, node& b) {
	target.sum = a.sum + b.sum;
	target.lsum = max(a.lsum, a.sum + b.lsum);
	target.rsum = max(b.rsum, b.sum + a.rsum);
	target.msum = max({ a.msum, b.msum, a.rsum + b.lsum });

	return;
}
void print(node& target) {
	cout << target.sum << ' ' << target.lsum << ' ' << target.rsum << ' ' << target.msum << '\n';
}
void add(node& target, ll val) {
	target.sum += val; target.lsum += val; target.rsum += val; target.msum += val;
	return;
}

int N = 4096;
node tree[8192];
//바텀업
void update(int target, ll val) {
	int idx = target + N;
	add(tree[idx], val);
	for (; idx > 1; idx >>= 1) {
		if (idx & 1) {
			add(tree[idx >> 1], tree[idx ^ 1], tree[idx]);
		}
		else {
			add(tree[idx >> 1], tree[idx], tree[idx ^ 1]);
		}
	}
}
//재귀
void upd(ll idx, ll start, ll end, ll target, ll val) {
	if (start == target && end == target) {
		add(tree[idx], val); //현재 노드에 target 더하기
		return;
	}

	if (start <= target && target <= end) {
		upd(idx * 2, start, (start + end) / 2, target, val);
		upd(idx * 2 + 1, (start + end) / 2 + 1, end, target, val);
		add(tree[idx], tree[idx * 2], tree[idx * 2 + 1]);
	}
}

void init() {
	for (int i = 0; i < 8192; i++) {
		tree[i].sum = tree[i].lsum = tree[i].rsum = tree[i].msum = 0;
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	freopen("input_10167.txt", "rt", stdin);
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y >> v[i].w;

		nx.push_back({ v[i].x, i });
		ny.push_back({ v[i].y, i });
	}
	sort(nx.begin(), nx.end());
	sort(ny.begin(), ny.end());

	//해싱함
	int max_x = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && nx[i - 1].first != nx[i].first)max_x++;

		v[nx[i].second].x = max_x;
	}
	int max_y = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && ny[i - 1].first != ny[i].first)max_y++;

		v[ny[i].second].y = max_y;
	}
	for (int i = 0; i < n; i++) {
		yy[v[i].y].push_back({ v[i].x, v[i].w });
	}
	ll ret = INT_MIN;
	for (int sy = 0; sy <= max_y; sy++) {
		init();
		for (int ey = sy; ey <= max_y; ey++) {
			for (auto val : yy[ey]) {
				//위치 : x, 값 : w
				update(val.first, val.second);
				//upd(1, 0, 4095, val.first, val.second);
			}
			ret = max(ret, tree[1].msum);

		}
	}
	cout << ret << '\n';
}