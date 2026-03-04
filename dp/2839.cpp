#include <bits/stdc++.h>
using namespace std;
int n, cnt;
const int INF = 1e9;
vector<int> dp(5004, INF);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;

    // 방법 1: 그리디
    // while (n >= 0) {
    //     if (n % 5 == 0) {
    //         cnt += n / 5;
    //         cout << cnt << "\n";
    //         return 0;
    //     }
    //     n -= 3;
    //     cnt++;
    // }
    // cout << -1 << "\n";
    // return 0;

    // 방법 2 : dp
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i >= 3) dp[i] = min(dp[i], dp[i-3] + 1);
        if (i >= 5) dp[i] = min(dp[i], dp[i-5] + 1);
    }

    if (dp[n] == INF) cout << -1 << "\n";
    else cout << dp[n] << "\n";
}