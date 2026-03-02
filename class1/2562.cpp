#include <bits/stdc++.h>
using namespace std;
int n, mx, idx;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 9; i++) {
        cin >> n;
        mx = max(n, mx);
        if (mx == n) idx = i + 1;
    }
    cout << mx << "\n";
    cout << idx << "\n";
}