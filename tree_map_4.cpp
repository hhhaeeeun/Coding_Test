#include <iostream>
#include<map>
using namespace std;
int n;
map<string, int> m;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s = " ";
        cin >> s;
        ++m[s];
    }
    for (auto i : m) {
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}