#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int main() {
    set < pair<int, int>> s;
    freopen("ts11.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int y = 0;  int x = 0; cin >> y >> x;
        s.insert({ x,y });
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string tem = ""; cin >> tem;
        if (tem == "ad") {
            int y = 0;  int x = 0; cin >> y >> x;
            s.insert({ x,y });
        }
        if (tem == "sv") {
            int y = 0;  int x = 0; cin >> y >> x;
            s.erase({ x,y });
        }
        if (tem == "rc") {
             int x = 0; cin >> x;
             if(x == 1)
                 cout << s.rbegin()->second << endl;
             if(x == -1)
                 cout << s.begin()->second << endl;
        }
    }
    return 0;
}