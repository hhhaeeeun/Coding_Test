#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;
int n, m;
unordered_set<int> g[250000];
vector<int> in_[250001];
bool visited[250001];
int main() {
    freopen("hs5.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int k = 0;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int tem = 0; cin >> tem;
            g[i].insert(tem);
            in_[tem].push_back(i);
        }
    }
    int ret = 1;
    queue<int> q;
    q.push(1);
    visited[1] = true;
    while (q.size()) {
        int x = q.front(); q.pop();
        for (auto i : in_[x]) {
            g[i].erase(x);
            if (g[i].size() == 1) {
                auto k = g[i].begin();
                if (visited[*k] == false) {
                    q.push(*k);
                    ret++;
                    visited[*k] = true;
                }
                g[i].erase(*k);
            }
        }
    }
    cout << ret;
    return 0;
}