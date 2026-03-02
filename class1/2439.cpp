#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << string(n-i, ' ') << string(i, '*') << "\n";
    }
}