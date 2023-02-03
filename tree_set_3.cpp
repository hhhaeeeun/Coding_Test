#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int main() {
    set<int> s;
    cin >> n>>m;
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        s.insert(x);
    }
    for (int j = 0; j < m; j++) {
        int x = 0;
        cin >> x;
        //auto k = lower_bound(s.begin(), s.end(), x);
        auto k = s.lower_bound(x);
        if (k == s.end()) {
            cout << "-1\n";
        }
        else
        {
            cout << *k << '\n';
        }
    }
    return 0;
}