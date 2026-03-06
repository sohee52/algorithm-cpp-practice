### 문제
- https://www.acmicpc.net/problem/1260
- https://www.acmicpc.net/problem/1325
- https://www.acmicpc.net/problem/14940
- https://www.acmicpc.net/problem/16918

### 정점 번호가 작은 것을 먼저 방문하는 DFS와 BFS
- https://www.acmicpc.net/problem/1260
- DFS와 BFS에서 정점 번호가 작은 것을 먼저 방문하기 위해서는, 인접 리스트에서 각 정점의 이웃들을 정렬해야 한다.
- 이때 주의해야 할 점은 정점 번호가 0부터 n-1까지인지, 1부터 n까지인지를 파악해야 한다는 점이다.
- 이 문제에선 정점 번호가 1부터 n까지이므로, 1부터 n까지 정렬해야 한다.
```cpp
for (int i = 1; i <= n; i++) {
    sort(adj[i].begin(), adj[i].end());
}
```

### 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력
- https://www.acmicpc.net/problem/1325
- `cnt++` 대신 `cnt += dfs(nx)`로 바꿔야 한다. 그래야 재귀적으로 방문한 정점의 개수를 더해줄 수 있다.
```cpp
int dfs(int x) {
    visited[x] = 1;
    int cnt = 1;
    for (int nx : adj[x]) {
        if (visited[nx]) continue;
        cnt += dfs(nx); // 재귀적으로 방문한 정점의 개수를 더해준다.
    }
    return cnt;
}
```

### 2차원 visited 배열 초기화하기
- https://www.acmicpc.net/problem/14940
```cpp
fill(&visited[0][0], &visited[0][0] + MAX*MAX, -1);
```
#### fill 설명
- 첫 번째와 두 번째 파라미터에 포인터가 들어가야 한다. `&visited[0][0]`은 2차원 배열의 첫 번째 요소의 주소를 가리키며, `&visited[0][0] + 1001 * 1001`은 배열의 끝을 가리킨다.
- 세 번째 파라미터엔 초기화하고자 하는 값을 넣는다. 이렇게 하면 `visited` 배열 전체를 0으로 초기화할 수 있다.
#### visited 배열 초기화 값 설명
- 이 문제에서는 방문하지 않은 정점과 애초에 갈 수 없는 정점, 방문한 정점을 구분해야 한다.
- 방문하지 않은 정점을 표현하기 위해 -1로 초기화한다.
- 애초에 갈 수 없는 정점은 0으로 표현한다.
- 방문한 정점은 1로 표현한다.

### 2차원 그래프 탐색 시 dy와 dx를 활용하기
- https://www.acmicpc.net/problem/14940

```cpp
const int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
}
```

### 2차원 그래프 탐색 시 범위 체크하기
- https://www.acmicpc.net/problem/14940

```cpp
// 범위 체크하기
if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
if (visited[ny][nx] != -1 || a[ny][nx] == 0) continue;

// 애초에 갈 수 없는 정점은 `a[i][j] == 0` 확인 후 0으로 출력하기
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        if (a[i][j] == 0) cout << 0 << " ";
        else cout << visited[i][j] << " ";
    }
    cout << "\n";
}
```

- 그래프 탐색할 때 `a[ny][nx] == 0`인 경우 탐색하면서 `visited[ny][nx] = 0`으로 바꾸지 않아야 한다.
- 우선 `continue;`로 탐색하지 않고 넘어가고, 나중에 출력할 때 `a[i][j] == 0`인 경우 0으로 출력하면 된다.

### 2차원 벡터 초기화하기
- https://www.acmicpc.net/problem/16918
```cpp
vector<string> ret(r, string(c, 'O'));
```
- 이렇게 하면 `ret` 벡터의 각 요소가 길이 `c`인 문자열로 초기화된다. 문자열의 각 문자는 'O'로 채워진다. 따라서 `ret`은 `r`개의 문자열로 이루어진 벡터가 된다.

### 3초 전 폭탄과 1초 전 폭탄 구분하기
- https://www.acmicpc.net/problem/16918
```cpp
vector<string> first = explode(a);
vector<string> second = explode(first);

if (n % 4 == 3) {
    for (string s : first) cout << s << "\n";
} else {
    for (string s : second) cout << s << "\n";
}
```
- 3초 전 폭탄과 1초 전 폭탄이 서로 다른 모양이므로, `explode` 함수를 두 번 호출하여 각각의 결과를 저장한다.
- 그리고 `n % 4`의 결과에 따라 출력할 벡터를 결정한다. `n % 4 == 3`인 경우에는 3초 전 폭탄이 남아있는 상태이므로 `first` 벡터를 출력하고, 그렇지 않은 경우에는 1초 전 폭탄이 남아있는 상태이므로 `second` 벡터를 출력한다.