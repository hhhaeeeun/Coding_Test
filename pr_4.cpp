#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int ret;
int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);


	int test_case;
	int T;
	freopen("sample_sample_input_pr_4.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{






		cout << "#" << test_case << " " << ret << '\n';
	}
	return 0;
}