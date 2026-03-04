#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v(24);
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
    cin >> n;
    v[0] = 0; v[1] = 1;
    for (int i = 2; i <= n; i++) {
        v[i] = v[i-1] + v[i-2];
    }
    cout << v[n] << "\n";
}