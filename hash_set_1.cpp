#include <iostream>
#include<unordered_set>
using namespace std;
int n;
unordered_set<int> s1;
int s2[1000001];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s = 0;
        cin >> s;
        s1.insert(s);
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s = 0;
        cin >> s;
        s2[i] = s;
    }
    for (int i = 0; i < n; i++) {
        if (s1.find(s2[i]) == s1.end()) {
            cout << 0 << ' ';
        }
        else
        {
            cout << 1 << ' ';
        }
    }

    return 0;
}