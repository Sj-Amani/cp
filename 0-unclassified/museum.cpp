#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const int sm = 1005;

int db[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int par[N], n, m;
int source;
int vis[N];
char s[sm][sm];

int dfs(int b, int y) {
  int id = b * m + y;
  if(s[b][y] == '*') return 1;
  if(vis[id] != -1) return 0;
  par[id] = source;
  vis[id] = 0;
  for(int i = 0; i < 4; i++) {
    vis[id] += dfs(b + db[i], y + dy[i]);
  }
  return vis[id];
}

int main() {
  for(int i = 0; i < N; i++) {
    par[i] = i;
  }
  
  int k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  memset(vis, -1, sizeof(vis));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if(vis[i*m + j] == -1 && s[i][j] == '.') {
        source = i * m + j;
        dfs(i, j);
      }
    }
  }
  while(k--) {
    int i, j;
    scanf("%d %d", &i, &j);
    i--; j--;
    printf("%d\n", vis[par[i * m + j]]);
  }
  
  return 0;
}
