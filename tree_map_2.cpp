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
        float k = (float)(i.second * 100) / (float)n;
        printf("%s %.4f\n", i.first.c_str(), k);

    }
    return 0;
}