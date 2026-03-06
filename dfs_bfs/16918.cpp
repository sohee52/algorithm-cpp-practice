#include <bits/stdc++.h>
using namespace std;
const int MAX = 204;
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};
int r, c, n;
vector<string> a;
bool visited[MAX][MAX];

vector<string> explode(vector<string> v) {
    fill(&visited[0][0], &visited[0][0] + MAX*MAX, 0);
    vector<string> ret(r, string(c, 'O'));

    for (int y = 0; y < r; y++) {
        for (int x = 0; x < c; x++) {
            if (v[y][x] == 'O') {
                visited[y][x] = 1; ret[y][x] = '.';
                for (int k = 0; k < 4; k++) {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                    if (visited[ny][nx]) continue;
                    visited[ny][nx] = 1; ret[ny][nx] = '.';
                }
            }
        }
    }

    return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> r >> c >> n;
    a.resize(r);
    for (int i = 0; i < r; i++) {
        cin >> a[i];
    }

    if (n == 1) {
        for (string s : a) cout << s << "\n";
    } else if (n % 2 == 0) {
        for (int i = 0; i < r; i++) cout << string(c, 'O') << "\n";
    } else {
        vector<string> first = explode(a);
        vector<string> second = explode(first);

        if (n % 4 == 3) {
            for (string s : first) cout << s << "\n";
        } else {
            for (string s : second) cout << s << "\n";
        }
    }
}