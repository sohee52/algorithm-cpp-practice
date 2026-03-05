### 문제
- https://www.acmicpc.net/problem/2748
- https://www.acmicpc.net/problem/1010
- https://www.acmicpc.net/problem/9655
- https://www.acmicpc.net/problem/1463

### long long
- https://www.acmicpc.net/problem/2748
- dp에선 웬만하면 타입을 long long으로 선언하는 것이 좋다. int로 선언했다가 오버플로우가 나서 디버깅하는 경우가 많기 때문이다.

### $mCn$
- https://www.acmicpc.net/problem/1010
- $mCn$을 dp로 표현하면 `dp[n][r] = dp[n-1][r-1] + dp[n-1][r]`이 된다.

### 마지막으로 1개 가져가거나 3개 가져가면 이기는 게임
- https://www.acmicpc.net/problem/9655
- 상대를 지는 상태로 보내면 SK가 이긴다.
- `dp[i-1] == false` 이면 → 1개 가져가서 CY가 지게 만들 수 있음 → SK 승리
- `dp[i-3] == false` 이면 → 3개 가져가서 CY가 지게 만들 수 있음 → SK 승리
- 그래서 점화식은 `dp[i] = (!dp[i-1]) || (!dp[i-3])`

### 최대한 적은 3kg나 5kg 봉지로 설탕 배달하기
- https://www.acmicpc.net/problem/2839

```cpp
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= 3) dp[i] = min(dp[i], dp[i-3] + 1);
        if (i >= 5) dp[i] = min(dp[i], dp[i-5] + 1);
    }
```

### 최솟값이 dp 값이 되는 경우 INF로 초기화하기
- https://www.acmicpc.net/problem/1463

```cpp
int dp[n+4];
fill(dp, dp + n + 4, INF);
```

### 한 계단 또는 두 계단씩 오르되, 연속된 세 계단은 밟지 않으며 계단 오르기
- https://www.acmicpc.net/problem/2579

```cpp
dp[i] = max(dp[i-3] + a[i-1], dp[i-2]) + a[i];
```