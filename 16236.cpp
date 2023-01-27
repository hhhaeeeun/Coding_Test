#include <iostream>
#include<algorithm>
#include<queue>

using namespace std;
int n;
int a[21][21];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};
int eat;
pair<int, int> shark;
int w_shark = 2;
int visited[21][21];
int bfs(int sy, int sx, int visited[][21]) {
    queue<pair<int,int>> q;
    q.push({ sy, sx });
    visited[sy][sx] = 1;
    int min_count = 0;
    int finish = false;
    vector<pair<int, int>> eat_fish;
    while (q.size()) {
        int y =q.front().first; int x = q.front().second;
        if (finish == true && visited[y][x] > min_count) break;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (a[ny][nx] > w_shark) continue;
            if (visited[ny][nx])continue;
            if (a[ny][nx] < w_shark && a[ny][nx] != 0) {
                /*
                ++eat;
                if (eat == w_shark) {
                    ++w_shark;
                    eat = 0;
                }
                shark.first = ny;
                shark.second = nx;
                a[ny][nx] = 0;
                return (visited[y][x]);
                */
                eat_fish.push_back({ ny,nx });
                min_count =  visited[y][x];
                finish = true;
            }
            else {
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ ny,nx });
            }
        }
    }
    if (eat_fish.size()) {
        sort(eat_fish.begin(), eat_fish.end());
        ++eat;
        if (eat == w_shark) {
            ++w_shark;
            eat = 0;
        }
        shark.first = eat_fish[0].first;
        shark.second = eat_fish[0].second;
        a[shark.first][shark.second] = 0;
        return (min_count);
    }
    return -1;
}
int main() {

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                shark.first = i;
                shark.second = j;
                a[i][j] = 0;
            }
        }
    }
    int ret = 0;
    int ans = 0;
    while (ret != -1) {
        ret = bfs(shark.first, shark.second, visited);
        if (ret == -1) break;
        ans += ret;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
            {
                visited[i][j] = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}