#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int n;
unordered_map<int, int> map;
int a[4][5000];
vector<pair<int, int>> v;
//O(N^3) => O(N^2);
int main() {
    cin >> n;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ++map[a[0][i] + a[1][j]];            
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = a[2][i] + a[3][j];
            k *= -1;
            if (map.count(k) == 1) {
                ret += map[k];
            }
        }
    }
    cout << ret;
    return 0;
}