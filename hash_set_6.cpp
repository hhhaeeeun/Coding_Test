#include <iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
int n, m;
unordered_set<int> g1;
unordered_set<int> temp;
unordered_set<int> g2;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        g1.insert(x);        
        temp.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x = 0;
        cin >> x;
        g2.insert(x);
    }


    for (auto i : g2)
    {
        if (g1.find(i) != g1.end()) {
            g1.erase(i);
        }
    }

    for (auto i : temp)
    {
        if (g2.find(i) != g2.end()) {
            g2.erase(i);
        }
    }

    cout << g1.size() + g2.size();
    return 0;
}