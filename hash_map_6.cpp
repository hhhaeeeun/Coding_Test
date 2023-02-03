#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
int n;
unordered_map<char, int> map;
int main() {
    freopen("ts7.txt", "r", stdin);
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        ++map[s[i]];
    }
    int ret = 0;
    char ans = ' ';
    for (auto i : map) {
        if (i.second == 1) {
            ret = 1;
            ans = i.first;
            break;
        }
    }
    if (ret == 0) {
        cout << "None\n";
        return 0;
    }
    cout << ans;
    return 0;
}