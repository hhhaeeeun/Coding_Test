#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n,m;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        set<int> s;
        cin >> m;
        for (int j = 0; j < m; j++) {
            string t = " "; int x = 0;
            cin >> t >> x;
            if (t == "I") {
                s.insert(x);
            }
            if (t == "D" && x == 1) {
                if(!s.empty())
                    s.erase(*s.rbegin());
            }
            if (t == "D" && x == -1) {
                if (!s.empty())
                    s.erase(*s.begin());
            }
        }
        if (s.empty()) {
            cout << "EMPTY\n";
        }
        else {
            cout << *s.rbegin() << ' ' << *s.begin() << '\n';
        }
    }
    return 0;
}