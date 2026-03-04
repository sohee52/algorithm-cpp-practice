#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    while (n >= 0) {
        if (n % 5 == 0) {
            cnt += n / 5;
            cout << cnt << "\n";
            return 0;
        }
        n -= 3;
        cnt++;
    }

    cout << -1 << "\n";
    return 0;
}