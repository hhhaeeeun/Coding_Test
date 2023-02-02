#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
int n,k;
unordered_set<int> a[10001];
int sit[10001];
vector<pair<int, int>>v;
int main() {
    cin >> n >> k;
    for (int i = 1; i < n+1; i++) {
        sit[i] = i;
        a[i].insert(i);
    }
    for (int i = 0; i < k; i++) {
        int x = 0; int y = 0;
        cin >> x >> y;
        v.push_back({ x,y });
        int tmp = sit[y];
        sit[y] = sit[x];
        a[sit[x]].insert(y);
        sit[x] = tmp;
        a[tmp].insert(x);
    }

    for (auto i : v) {
        int x = i.first; int y = i.second;
        int tmp = sit[y];
        sit[y] = sit[x];
        a[sit[x]].insert(y);
        sit[x] = tmp;
        a[tmp].insert(x);
    }
    for (auto i : v) {
        int x = i.first; int y = i.second;
        int tmp = sit[y];
        sit[y] = sit[x];
        a[sit[x]].insert(y);
        sit[x] = tmp;
        a[tmp].insert(x);
    }
    for (int i = 1; i < n + 1; i++) {
        cout << a[i].size() << endl;
    }


    return 0;
}