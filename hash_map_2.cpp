#include <iostream>
#include<unordered_map>
using namespace std;

int n;
long long m;
unordered_map<int, int> map;
int a[1000001];

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ret = 0;
    for (int i =0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cout << i << " " << j << endl;
            if (map.count(m - a[i] - a[j])) {
                ret += map[m - a[i] - a[j]];
            }
        }
        map[a[i]]++;
    }

    cout << ret;

    return 0;
}