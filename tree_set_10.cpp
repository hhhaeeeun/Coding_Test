#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int main() {
    set < pair<int, int>> s;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int y = 0;  int x = 0; cin >> y >> x;
        s.insert({ y,x });
    }
    for (int i = 0; i < m; i++) {
        int x = 0; cin >> x;
        auto k = s.lower_bound({ x,0 });
        if (k == s.end()) {
            cout << "-1 -1\n";
        }
        else
        {
            cout << k->first << ' ' << k->second << endl;
            s.erase(k);
        }
    }
    return 0;
}