#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int n;
unordered_map<int, int> map;
int a[4][5000];
vector<pair<int, int>> v;
int main() {
    cin >> n;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            if (i == 3) {
                ++map[a[i][j]];
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++)
            {
                int u = (a[0][i] + a[1][j] + a[2][k]) * (-1);
                if (map.count(u) == 1) {
                    ret += map[u];
                }
            }
        }
    }

    cout << ret;



    return 0;
}