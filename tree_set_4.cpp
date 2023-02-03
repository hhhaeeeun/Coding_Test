#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int main() {
    set<pair<int,int>> s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x = 0; int y = 0;
        cin >> y>>x;
        s.insert({ y,x });
    }
    for (int j = 0; j < m; j++) {
        int x = 0; int y = 0;
        cin >> y >> x;

        auto k = s.lower_bound({ y,x });
        if (k == s.end()) {
            cout << "-1 -1\n";
        }
        else
        {
            cout << k->first << ' '<<k->second << '\n';
        }
    }
    return 0;
}