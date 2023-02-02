#include <iostream>
#include<map>
using namespace std;
int n;
map<int, int> m;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s = 0;
        cin >> s;
        if (m.find(s) != m.end()) {
            //s가 있으면 pass
        }
        else {
            //s가 없으면 
            m[s] = i+1;
        }
    }
    for (auto i : m) {
        cout << i.first << ' ' << i.second << '\n';
    }
    return 0;
}