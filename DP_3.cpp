#include <iostream>
#include<algorithm>
#include <tuple>
#include<vector>
using namespace std;
int dp[1001][2];
int a[1001];
int main() {

    int n = 0;
    cin >> n;
    fill(&dp[0][0], &dp[1000][2], -1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = 0;
    dp[0][0] = 0; dp[0][1] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] < a[i])
            {
                dp[i][0] = max(dp[i][0], dp[j][0] + 1);
            }
            else if (a[j] > a[i]) {
                dp[i][1] = max(max(dp[j][0] + 1, dp[j][1] + 1), dp[i][1]);
            }
        }
    }

    int ret = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ret = max(ret, dp[i][j]);
        }
    }
    cout << ret;
   
    return 0;
}