#define _CRT_SECURE_NO_WARNINGS
#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;
int n, m,k;
int dy[5] = {0, -1, 1, 0, 0 };
int dx[5] = {0, 0, 0, 1, -1 };
int a[101][101];
struct SHARK {
	int y;
	int x;
	int s;
	int d;
	int z;
	bool dead;
};
vector<SHARK> v;
int ans;
void MoveSHARK() {
	int new_a[101][101] = {0, };
	for (int i = 0; i < v.size(); i++) {
		if (v[i].dead == true)continue;

		int ny = v[i].y;
		int nx = v[i].x;
		if( v[i].d == 1 || v[i].d == 2)
			v[i].s %= (2 * n - 2);
		else {
			v[i].s %= (2 * m - 2);
		}
		for (int k = 0; k < v[i].s; k++) {
			ny += dy[v[i].d];
			nx += dx[v[i].d];
			if (ny == 0) {
				ny = 2;
				v[i].d = 2;
			}
			if (ny > n) {
				ny = 2*n - ny;
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
		a[v[i].y][v[i].x] = 0;
		if (new_a[ny][nx]) {
			int ind = new_a[ny][nx];
			if (v[ind].z < v[i].z) {
				//이미 있는 물고기가 지금보다 작으면
				//있던 물고기가 죽는다
				new_a[ny][nx] = i;
				v[ind].dead = true;
				v[i].y = ny;
				v[i].x = nx;
			}
			else
			{
				//이미 있는물고기가 지금보다 더 크면
				//그렇지 않으면 지금 물고기가 죽는다..
				v[i].dead = true;
			}
		}
		else
		{
			//물고기가 없으면
			//자리를 차지하고 이전 자리를 비워준다.
			new_a[ny][nx] = i;
			v[i].y = ny;
			v[i].x = nx;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		if (v[i].dead == true)continue;
		a[v[i].y][v[i].x] = i;
	}
	return;
}
int GetFish(int col) {
	int eat_ind = -1;
	int eat_row = n + 1;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].dead == true)continue;
		if(v[i].x == col){
			if (eat_row > v[i].y) {
				eat_row = v[i].y;
				eat_ind = i;
			}		
		}
	}
	if (eat_ind != -1) {
		a[v[eat_ind].y][v[eat_ind].x] = 0;
		v[eat_ind].dead = true;
		ans += v[eat_ind].z;
	}
	return 0;
}
int main(int argc, char** argv)
{
	freopen("17143.txt", "r", stdin);
	cin >> n >> m >> k;
	v.push_back(SHARK{ 0,0,0,0,0,true });
	for (int i = 1; i <= k; i++)
	{
		SHARK t;
		cin >> t.y >> t.x >> t.s >> t.d >> t.z;
		t.dead = false;
		a[t.y][t.x] = i;
		v.push_back(t);
	}
	for (int i = 1; i <= m; i++) {
		GetFish(i);
		MoveSHARK();
	}
	cout << ans;
	return 0;
}