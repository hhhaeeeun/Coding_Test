#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<climits>
#include <tuple>
#include<queue>
using namespace std;
int n, m, k;
vector<vector<pair<int, int>>>v;
int dir[200001];
int main() {
    freopen("d2.txt", "r", stdin);
    cin >> n >> m;
    v.resize(n + 1);
    cin >> k;
    for (int i = 1; i <= m; i++) {
        int s = 0; int e = 0; int w = 0;
        cin >> s >> e >> w;
        v[s].push_back({ e,w });
        v[e].push_back({ s,w });
    }
    priority_queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++) {
        dir[i] = (int)1e9;
    }
    q.push({ 0, k });
    dir[k] = 0;
    while (q.size()) {
        int min_index = 0; int w = 0; tie(w, min_index) = q.top(); q.pop();
        if (dir[min_index] != -w)
            continue;
        for (auto i : v[min_index]) {
            if (dir[i.first] > dir[min_index] + i.second) {
                dir[i.first] = dir[min_index] + i.second;
                q.push({ -dir[i.first], i.first });
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dir[i] == (int)1e9) {
            cout << -1 << endl;
        }
        else
            cout << dir[i] << endl;
    }
    return 0;
}