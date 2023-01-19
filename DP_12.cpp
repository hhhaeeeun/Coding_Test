#include <iostream>
#include<algorithm>
#include<climits>
using namespace std;
int n;
int a[101];
int dp[101][100001];
int main() {

    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    fill(&dp[0][0], &dp[100][sum], INT_MIN);
    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = 1;
        for (int j = sum; j > 0; j--) {
            if (dp[i - 1][j] == 1)
                dp[i][j] = 1;
            if (j < a[i])continue;
            if(dp[i-1][j-a[i]] == 1)
                dp[i][j] = dp[i - 1][j - a[i]];

        }
    }
    int ret = INT_MAX;
    for (int j = 0;  j <sum ; j++) {
        if (dp[n][j] == 1)
            ret = min( abs(sum - j - j) , ret);
    }
    cout << ret;
    return 0;
}