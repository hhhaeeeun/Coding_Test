#include <iostream>
#include<unordered_map>
using namespace std;

int n;
long long m;
unordered_map<long long, int> map;
int a[1000001];

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        long long k = m - a[i];
        ret += map[a[i]];
        ++map[k];
    }

    cout << ret;
    
    return 0;
}