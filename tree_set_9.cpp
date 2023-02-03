#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n, m;
int main() {
    set<int> s;
    set<int> u;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x = 0; cin >> x;
        s.insert(x);
    }
    set<int>::iterator s_point = s.begin();
    set<int>::iterator e_point= s.end();
    --e_point;
    if (*e_point - *s_point < m) {
        cout << -1 << endl;
        return 0;
    }
    int ret = INT_MAX;
    e_point = ++s.begin();
    while (*e_point > *s_point) {
        if (e_point == s.end())break;
        int sub = *e_point - *s_point;

        if (sub < m) {
            ++e_point;
        }
        if (sub > m) {
            ++s_point;
            ret = min(sub, ret);
        }
        if (sub == m) {
            cout << m << endl;
            return 0;
        }
    }
    cout << ret;
    return 0;
}