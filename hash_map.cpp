#include <iostream>
#include<unordered_map>
using namespace std;
unordered_map<int, int> uom;
int n;
int main() {
    // ���⿡ �ڵ带 �ۼ����ּ���.
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s = ""; int key = 0; int val = 0;
        cin >> s >> key;
        if (s == "add")
        {
            cin >> val;
            uom[key] = val;
        }
        if (s == "find") {
            auto a = uom.find(key);
            if (a == uom.end())
                cout << "None\n";
            else
                cout << a->second << '\n';
        }
        if (s == "remove")
        {
            uom.erase(key);
        }
    }
    return 0;
}
