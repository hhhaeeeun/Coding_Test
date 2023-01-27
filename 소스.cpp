#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

struct box {
	int y;
	int x;
	int d;
};
vector<box> v;

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, 1, -1 };
int main() {

	int n = 4;
	int m = 8;
	v.push_back({ 1, 1, 2 });
	int ny = 1;
	int nx = 1;
	int i = 0;
	int move = 17;
	cout << ny << " " << nx << " " << v[0].d<<endl;
	for (int k = 0; k < move; k++) {
		ny += dy[v[i].d];
		nx += dx[v[i].d];
		if (ny == 0) {
			ny = 2;
			v[i].d = 2;
		}
		if (ny > n) {
			ny = 2 * n - ny;
			v[i].d = 1;
		}
		if (nx == 0) {
			nx = 2;
			v[i].d = 3;
		}
		if (nx > m) {
			nx = 2 * m - nx;
			v[i].d = 4;
		}
	}

	cout << ny << " " << nx << " " << v[0].d << endl;

	int a = 1 + dy[2] * move;
	cout << a << endl;
	a %= (2 * n - 2);
	cout << a << endl;
	return 0;

}