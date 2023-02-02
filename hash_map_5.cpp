#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int n;
unordered_map<string, int> map;
string a[5000];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ++map[s];
    }
    int ret = 0;
    for(auto i : map){
        if (i.second > ret)
            ret = i.second;
    }
    cout << ret;
    return 0;
}