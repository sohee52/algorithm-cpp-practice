#include <bits/stdc++.h>
using namespace std;
const int MAX = 1004;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int n, m, a[MAX][MAX], ty, tx, y, x, visited[MAX][MAX];
queue<pair<int, int>> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 2) {
                ty = i; tx = j;
            }
        }
    }

    fill(&visited[0][0], &visited[0][0] + MAX*MAX, -1);
    q.push({ty, tx}); visited[ty][tx] = 0;
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[ny][nx] != -1 || a[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0) cout << 0 << " ";
            else cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}