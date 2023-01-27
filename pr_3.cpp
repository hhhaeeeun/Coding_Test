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
		//�����ִ� ������ ��� �ð� ���
		d[i] = max(d[i], CPU[i] - a[cur][0]);
	}
	//dfs�� ������ ���� ������ ������ �� ��
	//���ϱ� 5�� �ϴ� ������ �ʱ�ȭ �ð��� �ٿ��ֱ� ����
	if (dp[cur][d[0]][d[1]][d[2]][d[3]][d[4]] == test_case * 5 + cpu_N)
		return false;
	for (int i = 0; i < cpu_N; i++) {
		//10�ʸ� ������ �Ұ���
		if (CPU[i] + a[cur][1] - a[cur][0] > 10) continue;

		int tmp = CPU[i];//�������� ������ �ð�
		if (d[i] == 0)//��Ⱑ ������
			CPU[i] = a[cur][1] + a[cur][0];
		else
			CPU[i] += a[cur][1];

		if (dfs(cur + 1, cpu_N))
		{
			//��Ʈ��ŷ
			CPU[i] = tmp;
			//�����ϴϱ� ���� true
			return true;
		}
		//�Ұ����ص� ��Ʈ��ŷ �ϴ� �ؾ���
		CPU[i] = tmp;
	}

	//�̰� ����?
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
		int i = 1;//���� ť�� ����
		
#if 0
		//1ť ���
		//����ð� - �����½ð� + �ɸ��½ð� > 10 �̸� ���ο� ť ���
		CPU[0] = a[0][0] + a[0][1];
		int num = 0; //���� ť�� ��ġ
		for (int i = 1; i < n; ++i) {
			if (ret == 5) {
				ret = -1;
				break;
			}
			for (int j = 0; j < ret; j++){//ret�� ť�߿��� ���� ���� ť�� ã��
				if (CPU[j] < CPU[num]) num = j;
			}
			if (a[i][0] >= CPU[num])
			{
				//q�� �ٷ� �������  �ٷ� ���� �ٷ� �ְ�
				CPU[num] = a[i][0] + a[i][1];
			}
			else if (a[i][0] < CPU[num]) {
				int wait = CPU[num] - a[i][0] + a[i][1];
				if (wait > 10) {
					//���ο� ť�� �����ؾ� ��
					++ret;
					CPU[ret - 1] = a[i][0] + a[i][1];
				}
				else if (wait <= 10) {
					//�ȳ����� �ּҿ��� �־� !
					CPU[num] += a[i][1];
				}
			}
		}
		for (int i = 0; i < 5; i++) {
			CPU[i] = 0;
		}
#endif

		for (i = 1; i <= 5; i++) {
			//1������ 5������ ��� ��ġ
			//�����ϸ� �ٷ� ���
			success = dfs(0, i);
			if (success) break;
		}
		if (!success) i = -1;


		cout << "#" << test_case << " " << i << '\n';
	}
	return 0;
}