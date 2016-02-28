#include <bits/stdc++.h>

using namespace std;

const int N = 205;

string str = "URDL";

int da[] = {-1, 0, 1, 0};
int db[] = {0, 1, 0, -1};
char s[N];

int main() {
  int n;
  scanf("%d %s", &n, s);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    for(int j = i; j < n; j++) {
      int a = 0, b = 0;
      for(int k = i; k <= j; k++) {
        for(int t = 0; t < 4; t++) {
          if(s[k] == str[t]) {
            a += da[t];
            b += db[t];
          }
        }
      }
      if(a == 0 && b == 0) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}