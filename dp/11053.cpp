#include <bits/stdc++.h>
using namespace std;
int n, a[1004], dp[1004];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    fill(dp, dp + 1004, 1);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, dp[i]);
    }
    cout << mx << "\n";
}