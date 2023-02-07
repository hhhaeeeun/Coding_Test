#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<climits>
#include<set>
using namespace std;
vector<pair<int, int>>points;
int n;
set<int> s;
int a[1000][1000];
int ps[1000][1000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x = 0; int y = 0;
        cin >> x >> y;
        s.insert(x);
        s.insert(y);
        points.push_back({ x,y });
    }
    unordered_map<int, int> m;
    int cnt = 1;
    for (auto i : s) {
        m[i] = cnt;
        cnt++;
    }

    for (auto i : points) {
        a[m[i.first]][m[i.second]] = 1;
    }

    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= cnt; j++) {
            ps[i][j] = ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1] + a[i][j];
        }
    }
    int ret = INT_MAX;
    for (int i = 1; i <= cnt; i++) {
        for (int j = 1; j <= cnt; j++) {
            int tmp[4] = { 0 };
            int ans = 0;
            tmp[0] = ps[i][j];
            tmp[1] = ps[i][cnt] - ps[i][j];
            tmp[2] = ps[cnt][j] - ps[i][j];
            tmp[3] = ps[cnt][cnt] - tmp[0] - tmp[1] - tmp[2];
            for (int kkk = 0; kkk < 4; kkk++) {
                ans = max(ans, tmp[kkk]);
            }
            ret = min(ret, ans);
        }
    }
    cout << ret;
    return 0;
}
#if 0
#include <iostream>
#include <algorithm>
#include <tuple>
#include <climits>

#define MAX_N 1000
#define MAX_R 1000
#define MAX_Q 4

using namespace std;

// 변수 선언
int n;
pair<int, int> points[MAX_N];

int ans = INT_MAX;

int main() {
    // 입력:
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    // x 기준 오름차순으로 정렬합니다.
    sort(points, points + n);

    // y = b를 먼저 설정합니다.
    for (int b = 0; b <= MAX_R; b += 2) {
        // 1, 2, 3, 4 각 사분면에 
        // 들어 있는 점의 개수를 관리합니다.
        int cnt[MAX_Q + 1] = {};

        // 먼저 x = 0일 때의
        // 1, 2, 3, 4 각 사분면에
        // 있는 점의 수를 계산합니다. 
        // 모든 점은 x = 0 보다 오른쪽에 있으므로
        // 이는 y좌표에 따라 1, 4 사분면으로 나뉘게 됩니다.
        for (int i = 0; i < n; i++) {
            int y;
            tie(ignore, y) = points[i];

            if (y > b)
                cnt[1]++;
            else
                cnt[4]++;
        }

        // 이제 x 기준 오름차순으로 정렬된 
        // n개의 점을 보며 
        // 각 점을 순서대로 왼쪽으로 보내며
        // 1 -> 2 사분면으로
        // 4 -> 3 사분면으로 점들의 위치를 보정해줍니다.
        for (int i = 0; i < n; i++) {
            // 새로운 x값이 시작되는 경우에는
            // 답을 갱신해줍니다.
            if (i == 0 || points[i].first != points[i - 1].first) {
                int max_cnt = 0;
                for (int j = 1; j <= MAX_Q; j++)
                    max_cnt = max(max_cnt, cnt[j]);

                ans = min(ans, max_cnt);
            }

            // i번 점의 위치를 보정해줍니다.
            int y;
            tie(ignore, y) = points[i];
            if (y > b) {
                cnt[1]--;
                cnt[2]++;
            }
            else {
                cnt[4]--;
                cnt[3]++;
            }
        }
    }
    cout << ans;
    return 0;
}
#endif