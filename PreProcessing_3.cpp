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

// ���� ����
int n;
pair<int, int> points[MAX_N];

int ans = INT_MAX;

int main() {
    // �Է�:
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    // x ���� ������������ �����մϴ�.
    sort(points, points + n);

    // y = b�� ���� �����մϴ�.
    for (int b = 0; b <= MAX_R; b += 2) {
        // 1, 2, 3, 4 �� ��и鿡 
        // ��� �ִ� ���� ������ �����մϴ�.
        int cnt[MAX_Q + 1] = {};

        // ���� x = 0�� ����
        // 1, 2, 3, 4 �� ��и鿡
        // �ִ� ���� ���� ����մϴ�. 
        // ��� ���� x = 0 ���� �����ʿ� �����Ƿ�
        // �̴� y��ǥ�� ���� 1, 4 ��и����� ������ �˴ϴ�.
        for (int i = 0; i < n; i++) {
            int y;
            tie(ignore, y) = points[i];

            if (y > b)
                cnt[1]++;
            else
                cnt[4]++;
        }

        // ���� x ���� ������������ ���ĵ� 
        // n���� ���� ���� 
        // �� ���� ������� �������� ������
        // 1 -> 2 ��и�����
        // 4 -> 3 ��и����� ������ ��ġ�� �������ݴϴ�.
        for (int i = 0; i < n; i++) {
            // ���ο� x���� ���۵Ǵ� ��쿡��
            // ���� �������ݴϴ�.
            if (i == 0 || points[i].first != points[i - 1].first) {
                int max_cnt = 0;
                for (int j = 1; j <= MAX_Q; j++)
                    max_cnt = max(max_cnt, cnt[j]);

                ans = min(ans, max_cnt);
            }

            // i�� ���� ��ġ�� �������ݴϴ�.
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