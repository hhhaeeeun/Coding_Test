#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int main() {
    set<int> s;
    cin >> n >> m;
    for (int j = 1; j <= m; j++) {
        s.insert(j);
    }
    for (int i = 0; i < n; i++) {
        int x = 0; cin >> x;
        s.erase(x);
        cout << *s.rbegin() <<'\n';
    }
    return 0;
}