#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const long long inf = 1e18;

string s[N][2];
long long dp[N][2];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    cin >> s[i][0];
    s[i][1] = s[i][0];
    reverse(s[i][1].begin(), s[i][1].end());
  }
  for (int i = 0; i < N; i++) dp[i][0] = dp[i][1] = inf;
  dp[0][0] = 0;
  dp[0][1] = a[0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        if (s[i - 1][k] <= s[i][j]) {
          dp[i][j] = min(dp[i][j], dp[i - 1][k] + (j? a[i] : 0));
        }
      }
    }
  }
  long long ans = min(dp[n - 1][0], dp[n - 1][1]);
  if (ans == inf) ans = -1;
  cout << ans << endl;
  return 0;
}
