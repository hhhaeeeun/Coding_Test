#include <iostream>
#include<map>
using namespace std;
int n;
map<int, int> m;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; int x = 0; int y = 0;
        cin >> s;
        if (s == "add")
        {
            cin >> x >> y;
            m[x] = y;
        }
        if (s == "find") {
            cin >> x;
            if (m.find(x) == m.end()) {
                cout << "None\n";
            }
            else
                cout << m[x] << '\n';
        }
        if (s == "remove") {
            cin >> x;
            m.erase(x);
        }
        if (s == "print_list") {
            if (m.empty()) {
                cout << "None\n";
            }
            else {
                for (auto i : m) {
                    cout << i.second << ' ';
                }
                cout << '\n';
            }
        }
    }
    return 0;
}