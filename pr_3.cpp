#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;
int test_case;
int n;
int a[1001][2];
int CPU[5];
int dp[1000][11][11][11][11][11];
bool success;
bool dfs(int cur, int cpu_N) {
	if (cur == n) {
		return true;
	}
	int d[5] = { 0, };
	for (int i = 0; i < cpu_N; i++) {
		//현재있는 갯수에 대기 시간 계산
		d[i] = max(d[i], CPU[i] - a[cur][0]);
	}
	//dfs를 수행한 적이 있으면 실패한 것 임
	//곱하기 5를 하는 이유는 초기화 시간을 줄여주기 위함
	if (dp[cur][d[0]][d[1]][d[2]][d[3]][d[4]] == test_case * 5 + cpu_N)
		return false;
	for (int i = 0; i < cpu_N; i++) {
		//10초를 넘으면 불가능
		if (CPU[i] + a[cur][1] - a[cur][0] > 10) continue;

		int tmp = CPU[i];//이전까지 끝나는 시간
		if (d[i] == 0)//대기가 없으면
			CPU[i] = a[cur][1] + a[cur][0];
		else
			CPU[i] += a[cur][1];

		if (dfs(cur + 1, cpu_N))
		{
			//백트레킹
			CPU[i] = tmp;
			//가능하니까 리턴 true
			return true;
		}
		//불가능해도 백트래킹 일단 해야함
		CPU[i] = tmp;
	}

	//이게 뭐야?
	dp[cur][d[0]][d[1]][d[2]][d[3]][d[4]] = test_case * 5 + cpu_N;
	return false;
}


int main(int argc, char** argv)
{

	int T;
	freopen("sample_sample_input_pr_3.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> a[i][0] >> a[i][1];
		}
		int i = 1;//현재 큐의 개수
		
#if 0
		//1큐 사용
		//현재시각 - 끝나는시간 + 걸리는시간 > 10 이면 새로운 큐 사용
		CPU[0] = a[0][0] + a[0][1];
		int num = 0; //넣을 큐의 위치
		for (int i = 1; i < n; ++i) {
			if (ret == 5) {
				ret = -1;
				break;
			}
			for (int j = 0; j < ret; j++){//ret의 큐중에서 가장 빠른 큐를 찾아
				if (CPU[j] < CPU[num]) num = j;
			}
			if (a[i][0] >= CPU[num])
			{
				//q가 바로 비워지면  바로 빼고 바로 넣고
				CPU[num] = a[i][0] + a[i][1];
			}
			else if (a[i][0] < CPU[num]) {
				int wait = CPU[num] - a[i][0] + a[i][1];
				if (wait > 10) {
					//새로운 큐를 생성해야 함
					++ret;
					CPU[ret - 1] = a[i][0] + a[i][1];
				}
				else if (wait <= 10) {
					//안넘으면 최소에다 넣어 !
					CPU[num] += a[i][1];
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			CPU[i] = 0;
		}
#endif

		for (i = 1; i <= 5; i++) {
			//1개부터 5개까지 모두 서치
			//가능하면 바로 출력
			success = dfs(0, i);
			if (success) break;
		}
		if (!success) i = -1;


		cout << "#" << test_case << " " << i << '\n';
	}
	return 0;
}