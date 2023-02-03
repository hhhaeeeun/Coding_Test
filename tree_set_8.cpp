#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int main() {
    set<int> s;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        s.insert(i);
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        auto k = s.upper_bound(x);
        if (k == s.begin())
        {
            break;
        }
        --k;
        s.erase(*k);
        ret++;
        if (s.size() == 0) break;
    }
    cout << ret << endl;
    return 0;
}