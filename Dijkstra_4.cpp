#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include<climits>
#include <tuple>
#include<queue>
#include<stack>
using namespace std;
int n, m;
vector<vector<pair<int, int>>>v;
int dir[200001];
int main() {
    freopen("d4.txt", "r", stdin);
    cin >> n >> m;
    v.resize(n + 1);
    for (int i = 1; i <= m; i++) {
        int s = 0; int e = 0; int w = 0;
        cin >> s >> e >> w;
        v[s].push_back({ e,w });
        v[e].push_back({ s,w });
    }
    int s = 0; int e = 0;
    cin >> s >> e;
    for (int i = 1; i <= n; i++) {
        dir[i] = (int)1e9;
    }
    dir[e] = 0;
    priority_queue<pair<int, int>> q;
    q.push({ 0, e });
    while (q.size()) {
        int min_index = 0; int w = 0; tie(w, min_index) = q.top(); q.pop();
        if (dir[min_index] != -w)continue;
        for (auto i : v[min_index]) {
            if (dir[i.first] > dir[min_index] + i.second) {
                dir[i.first] = dir[min_index] + i.second;
                q.push({ -dir[i.first] ,i.first });
            }
        }
    }
    queue<int> sta;
    int x = s;
    sta.push(s);
    while(x != e){
        sort(v[x].begin(), v[x].end());
        for (auto i : v[x]) {
            if (dir[x] == dir[i.first] + i.second) {
                sta.push(i.first);
                x = i.first;
                break;
            }
        }
    }
    cout << dir[s] << endl;
    while (sta.size()) {
        cout << sta.front() << ' ';
        sta.pop();
    }
    return 0;
}