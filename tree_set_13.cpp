#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
set<int> s;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x = 0; cin >> x;
        s.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x = 0; cin >> x;
        auto k = s.upper_bound(x);
        if (k == s.begin()) {
            cout << "-1\n";
            continue;
        }
        --k;
        if (*k > x) {
            cout << "-1\n";
        }
        cout << *k << '\n';
        s.erase(k);
    }
    return 0;
}
