#include <bits/stdc++.h>
using namespace std;
int n, m, v, a, b;
vector<int> adj[10004];
bool visited[10004];
queue<int> q;

void dfs(int x) {
    visited[x] = 1;
    cout << x << " ";
    for (int nx : adj[x]) {
        if (visited[nx]) continue;
        dfs(nx);
    }
}

void bfs() {
    while(q.size()) {
        int x = q.front(); q.pop();
        cout << x << " ";
        for (int nx : adj[x]) {
            if (visited[nx]) continue;
            visited[nx] = 1;
            q.push(nx);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    dfs(v);

    cout << "\n";

    fill(visited, visited + 10004, false);
    q.push(v);
    visited[v] = 1;
    bfs();
    cout << "\n";
}