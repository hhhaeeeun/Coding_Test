#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define max_candy 1000000
int n;
int candyTree[max_candy * 4];
int outCandy;

void update(int idx, int now, int start, int end, int diff) {

    if (idx < start || end < idx)
        return;
    if (start == end) {
        candyTree[now] += diff;
        return;
    }
    if (start <= idx && idx <= end) {
        candyTree[now] += diff;
        int mid = (start + end) / 2;
        update(idx, now * 2, start, mid, diff);
        update(idx, now * 2 + 1, mid + 1, end, diff);
    }
    return;
}
void push(int taste, int num) {
    update(taste, 1, 1, max_candy, num);
}
int findCandy(int rank, int idx, int start, int end) {
    if (start == end) {
        outCandy = start;
        --candyTree[idx];
        return -1;
    }

    if (candyTree[idx] >= rank) {
        int mid = (start + end) / 2;
        if (candyTree[idx * 2] >= rank) {
            candyTree[idx] += findCandy(rank, idx * 2, start, mid);
        }
        else {
            candyTree[idx] += findCandy(rank - candyTree[idx * 2], idx * 2 + 1, mid + 1, end);
        }
    }
    return -1;
}
void out(int rank) {
    findCandy(rank, 1, 1, max_candy);
}
int main() {
    cin.tie(NULL); ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a;
        if (a == 1) {
            cin >> b;
            out(b);
            if (outCandy) {
                cout << outCandy << '\n';
            }
            outCandy = 0;
        }
        else if (a == 2) {
            cin >> b >> c;
            push(b, c);
        }
    }
    return 0;
}