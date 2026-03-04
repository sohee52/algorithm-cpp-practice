#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t;
int n, m;
ll c[31][31];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i <= 30; i++) {
    c[i][0] = 1; c[i][i] = 1;
    for (int j = 1; j < i; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }

  cin >> t;
  while (t--) {
    cin >> n >> m;
    cout << c[m][n] << "\n";
  }
}