#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int main() {
    freopen("ts7.txt", "r", stdin);
    set<int> s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        s.insert(x);
    }
    int k = 0;
    auto u = s.end();
    --u;
    while(1){
        cout << *u << ' ';
        --u;
        ++k;
        if (k == m)
            break;
    }
    return 0;
}