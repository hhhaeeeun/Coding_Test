#include <iostream>
#include<algorithm>
#include<set>
#include<climits>
#include<cstdlib>
using namespace std;
int n;
int min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}
int main() {
    set<int> s;
    cin >> n;
    int ret = INT_MAX;
    s.insert(0);
    for (int i = 0; i < n; i++) {
        int x = 0; cin >> x;
        auto k = s.upper_bound(x);
        if (k != s.end()) {
            ret = min(ret, *k - x);
        }
        k = s.lower_bound(x);
        --k;     
        ret = min(ret, x - *k);
        cout << ret << '\n';
        s.insert(x);
    }
    return 0;
}