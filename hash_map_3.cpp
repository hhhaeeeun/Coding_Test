#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int m;
unordered_map<int, int> map;
int a[1000001];
vector<pair<int, int>> v;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        map[a[i]]++;
    }
    int ret = 0;
    for (auto i : map) {
        v.push_back({ i.second,  i.first });
    }
    sort(v.begin(), v.end(), greater<>());
    for (int i = 0; i < m; i++) {
        cout << v[i].second <<' ';
    }
    return 0;
}