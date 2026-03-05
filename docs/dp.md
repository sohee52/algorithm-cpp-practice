### 문제
- https://www.acmicpc.net/problem/2748
- https://www.acmicpc.net/problem/1010
- https://www.acmicpc.net/problem/9655
- https://www.acmicpc.net/problem/2839
- https://www.acmicpc.net/problem/1463
- https://www.acmicpc.net/problem/2579
- https://www.acmicpc.net/problem/11726
- https://www.acmicpc.net/problem/2407
- https://www.acmicpc.net/problem/17626

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

### 2xn 타일링
- https://www.acmicpc.net/problem/11726
- 마지막이 세로 타일이라면 `dp[i-1]`가지 경우가 있고, 마지막이 가로 타일이라면 `dp[i-2]`가지 경우가 있다.
- 두 경우는 겹치지 않으므로 이 둘을 더하면 된다.
- 이때, 답이 매우 커질 수 있으므로 10007로 나눈 나머지를 저장해야 한다.
```cpp
dp[i] = (dp[i-1] + dp[i-2]) % 10007;
```

### long long보다 큰 수여서, string으로 더해야 하는 경우
- https://www.acmicpc.net/problem/2407

```cpp
string addStr(string a, string b) {
    // 일의 자리부터 더하기 쉽도록 문자열을 뒤집음
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // 두 숫자 중 더 긴 자릿수만큼은 반드시 계산해야 하므로 길이 계산
    int lenA = a.length();
    int lenB = b.length();
    int len = max(lenA, lenB);

    // 최종 결과를 저장할 num
    string num = "";

    // 현재 자리의 총합(자릿수 + carry)을 저장할 sum
    int sum = 0;

    // 가장 긴 자릿수(len)까지 혹은 carry(sum)가 남아있을 때까지
    for (int i = 0; i < len || sum; i++) {
        // 기존 carry(sum)에 현재 자리 숫자를 더함
        if (lenA > i) sum += a[i] - '0';
        if (lenB > i) sum += b[i] - '0';

        // sum % 10은 일의 자리의 결과 숫자만 뽑아냄
        // 문자열이 되도록 '0'을 붙여서 num에 넣기
        num += (sum % 10) + '0';

        // sum / 10은 carry를 의미. 다음 계산에 반영
        sum /= 10;
    }

    // 결과가 뒤집힌 상태이므로 다시 원래 순서로 뒤집기
    reverse(num.begin(), num.end());

    return num;
}
```

### 어떤 자연수를 제곱수의 합으로 나타내기
- https://www.acmicpc.net/problem/17626

```cpp
vector<int> dp(n+4, INF);
dp[0] = 0; dp[1] = 1;
for (int i = 1; i <= n; i++) {
    for (int j = 1; j * j <= i; j++) {
        dp[i] = min(dp[i], dp[i - j*j] + 1);
    }
}
```