#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;
int n, m;
int a[500][50];
int b[500][50];
vector<pair<int, int>>v;
int ret;
bool is_possible(vector<int> v) {
    unordered_set<string> set_map;
    
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < v.size(); j++) {
            s += a[i][v[j]];
        }
        set_map.insert(s);
    }

    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < v.size(); j++) {
            s += b[i][v[j]];
        }
        if (set_map.find(s) != set_map.end()) {
            return false;
        }
    }
    return true;
}
void combi(int now, vector<int> &v) {
    if (v.size() ==3) {
        //»Æ¿Œ
        if (is_possible(v)) {
            ret++;
        }
        return;
    }

    for (int i = now+1; i < m; i++) {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string s = " ";
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
        }
    }
    for (int i = 0; i < n; i++) {
        string s = " ";
        cin >> s;
        for (int j = 0; j < m; j++) {
            b[i][j] = s[j];
        }
    }

    vector<int> v;
    combi(-1, v);
    cout << ret;
    return 0;
}