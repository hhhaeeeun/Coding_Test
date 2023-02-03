#include <iostream>
#include<algorithm>
#include<set>
#include<time.h>
using namespace std;
int n, m;
int main() {
    set<int> s;
    n = 1000;
    for (int i = 0; i < n; i++) {
        s.insert(i);
    }
    clock_t start = clock();
    //auto k = lower_bound(s.begin(), s.end(), x);
    for (int i = 0; i < n; i++) {
        auto k = s.lower_bound(i);
    }
    clock_t end = clock();
    printf("fast 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);

    start = clock();
    for (int i = 0; i < n-1; i++) {
        auto k = lower_bound(s.begin(), s.end(), i);
    }
    end = clock();
    printf("slow 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}