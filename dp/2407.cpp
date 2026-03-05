#include <bits/stdc++.h>
using namespace std;

int n, m;
string dp[104][104];

string addStr(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    string num = "";
    int lenA = a.length();
    int lenB = b.length();
    int len = lenA > lenB ? lenA : lenB;
    int sum = 0;

    for (int i = 0; i < len || sum; i++) {
        if (lenA > i) sum += a[i] - '0';
        if (lenB > i) sum += b[i] - '0';
        num += (sum % 10) + '0';
        sum /= 10;
    }
    
    reverse(num.begin(), num.end());

    return num;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

    for (int i = 0; i <= n; i++) {
        dp[i][0] = "1"; dp[i][i] = "1";
        for (int j = 1; j < i; j++) {
            dp[i][j] = addStr(dp[i-1][j-1], dp[i-1][j]);
        }
    }

    cout << dp[n][m] << "\n";
}