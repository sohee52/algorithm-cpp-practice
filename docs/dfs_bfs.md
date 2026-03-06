### 문제
- https://www.acmicpc.net/problem/1260

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