#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
long long n;
unordered_map<long long, long long> map;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x = 0; long long y = 0;
        cin >> x >>y;
        if (map.count(x) == 0)
            map[x] = y;
        else {
            if (map[x] > y)
                map[x] = y;
        }
    }
    int ret = 0;
    for (auto i : map) {
        ret += i.second;
    }
    cout << ret;
    return 0;
}