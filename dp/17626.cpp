#include <bits/stdc++.h>
using namespace std;
int n;
const int INF = 1e9;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cin >> n;
    vector<int> dp(n+4, INF);
    dp[0] = 0; dp[1] = 1;
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    cout << dp[n] << "\n";
}