#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll dp[1004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
    cin >> n;

    // if (n % 2 == 1) cout << "SK" << "\n";
    // else cout << "CY" << "\n";

    // dp 버전
    dp[1] = 1;
    dp[2] = 0;
    dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        dp[i] = (!dp[i-1]) || (!dp[i-3]);
    }

    if (dp[n]) cout << "SK" << "\n";
    else cout << "CY" << "\n";
}