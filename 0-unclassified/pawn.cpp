#include <bits/stdc++.h>

using namespace std;

const int N = 10;

char s[N][N];

int main() {
  for(int i = 0; i < 8; i++) {
    scanf("%s", s[i]);
  }
  int a = 20, b = 20;
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      bool ada = 0;
      for(int k = 0; k < i; k++) {
        if(s[k][j] == 'B') ada = 1;
      }
      if(s[i][j] == 'W' && !ada) {
        a = min(a, i);
      }
      
      ada = 0;
      for(int k = i + 1; k < 8; k++) {
        if(s[k][j] == 'W') ada = 1;
      }
      if(s[i][j] == 'B' && !ada) {
        b = min(b, 7 - i);
      }
    }
  }
  puts(a <= b? "A" : "B");
  return 0;
}
