#include <bits/stdc++.h>
using namespace std;
const int MAX = 100004;
int n, m, a, b, ret[MAX], mx;
vector<int> adj[MAX];
bool visited[MAX];

int dfs(int x) {
    visited[x] = 1;
    int cnt = 1;
    for (int nx : adj[x]) {
        if (visited[nx]) continue;
        cnt += dfs(nx);
    }
    return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        fill(visited, visited + MAX, 0);
        ret[i] = dfs(i);
        mx = max(mx, ret[i]);
    }

    for (int i = 1; i <= n; i++) {
        if (mx == ret[i]) cout << i << " ";
    }
}