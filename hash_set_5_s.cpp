#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
#include<queue>
using namespace std;
int n, m;
int k[250000];
unordered_set<int> g[250000];
unordered_set<int> visited;
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> k[i];
        for (int j = 0; j < k[i]; j++) {
            int tem = 0; cin >> tem;
            g[i].insert(tem);
        }
    }
    int ret = 1;
    visited.insert(1);
    bool bp = true;
    while (bp == true) {
        bp = false;
        for (int indx = 0; indx < m; indx++) {
            if (k[indx] == 0) {
                continue;
            }
            if (g[indx].size() > visited.size() + 1) {
                continue;
            }
            int find_k = 0;
            for (auto i : visited) {
                if (g[indx].find(i) != g[indx].end()) {
                    g[indx].erase(i);
                }
            }
            if (g[indx].size() == 1) {
                for (auto i : g[indx]) {
                    visited.insert(i);
                }
                k[indx] = 0;
                bp = true;
            }
        }
    }
    cout << visited.size();
    return 0;
}