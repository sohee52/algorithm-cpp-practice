### 문제
- https://www.acmicpc.net/problem/2748
- https://www.acmicpc.net/problem/1010

### long long
- https://www.acmicpc.net/problem/2748
- dp에선 웬만하면 타입을 long long으로 선언하는 것이 좋다. int로 선언했다가 오버플로우가 나서 디버깅하는 경우가 많기 때문이다.

### $mCn$
- https://www.acmicpc.net/problem/1010
- $mCn$을 dp로 표현하면 `dp[n][r] = dp[n-1][r-1] + dp[n-1][r]`이 된다.