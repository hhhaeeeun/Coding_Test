#include <iostream>
#include<algorithm>
#include<set>
using namespace std;
int n;
int main() {
    set<int> s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t = "";
        cin >> t;
        if (t == "add") {
            int x = 0;
            cin >> x;
            s.insert(x);
        }
        if (t == "upper_bound") {
            int x = 0;
            cin >> x;
            auto k = upper_bound(s.begin(), s.end(), x);
            if (k == s.end()) {
                cout << "None\n";
            }
            else
            {
                cout << *k << '\n';
            }
        }
        if (t == "lower_bound") {
            int x = 0;
            cin >> x;
            auto k = lower_bound(s.begin(), s.end(), x);
            if (k == s.end()) {
                cout << "None\n";
            }
            else
            {
                cout << *k << '\n';
            }
        }
        if (t == "remove") {
            int x = 0;
            cin >> x;
            s.erase(x);
        }
        if (t == "find") {
            int x = 0;
            cin >> x;
            if (s.find(x) == s.end()) {
                cout << "false\n";
            }
            else
            {
                cout << "true\n";
            }
        }
        if (t == "largest") {
            if (s.empty()) {
                cout << "None\n";
            }
            else {
                cout << *s.rbegin() << '\n';
            }
        }
        if (t == "smallest") {
            if (s.empty()) {
                cout << "None\n";
            }
            else {
                cout << *s.begin() << '\n';
            }
        }
    }
    return 0;
}