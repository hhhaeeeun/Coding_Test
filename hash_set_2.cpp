#include <iostream>
#include<unordered_set>
using namespace std;
int n;
unordered_set<int> s1;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s = 0;
        cin >> s;
        s1.insert(s);
    }
    cout << s1.size();
    return 0;
}