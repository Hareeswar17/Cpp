#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; i++) cin >> S[i];

    const int INF = 1e9;

    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<pair<int,int>> q;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (S[i][j] == '#') {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dx[] = {-1,-1,-1,0,0,1,1,1};
    int dy[] = {-1,0,1,-1,1,-1,0,1};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W)
                continue;

            if (dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    // 10^100 is even
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << (dist[i][j] % 2 == 0 ? '#' : '.');
        }
        cout << '\n';
    }

    return 0;
}