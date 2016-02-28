#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

long long a[N << 2], push[N << 2];
int c[N], pos[N], q[N], cntr;
vector<int> edge[N];

void dfs(int now, int bef) {
  pos[now] = cntr++;
  for(auto it : edge[now]) {
    if(it == bef) continue;
    dfs(it, now);
  }
  q[now] = cntr - 1;
}

void relax(int p, int l, int r) {
  if(push[p] != -1) {
    if(l != r) {
      push[p + p] = push[p];
      push[p + p + 1] = push[p];
    }
    a[p] = push[p];
    push[p] = -1;
  }
}

void combine(int p, int l, int r) {
  a[p] = (a[p + p] | a[p + p + 1]);
}

void update(int p, int l, int r, int ll, int rr, long long val) {
  relax(p, l, r);
  if(r < ll || rr < l) return;
  if(ll <= l && r <= rr) {
    push[p] = val;
    relax(p, l, r);
    return;
  }
  int mid = (l + r) >> 1;
  update(p + p, l, mid, ll, rr, val);
  update(p + p + 1, mid + 1, r, ll, rr, val);
  combine(p, l, r);
}

long long find(int p, int l, int r, int ll, int rr) {
  relax(p, l, r);
  if(r < ll || rr < l) return 0;
  if(ll <= l && r <= rr) return a[p];
  int mid = (l + r) >> 1;
  long long ret = (find(p + p, l, mid, ll, rr) | find(p + p + 1, mid + 1, r, ll, rr));
  combine(p, l, r);
  return ret;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; i++) {
    scanf("%d", c + i);
  }
  for(int i = 1; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  dfs(1, 0);
  memset(push, -1, sizeof(push));
  for(int i = 1; i <= n; i++) {
    update(1, 0, cntr - 1, pos[i], pos[i], (1LL << c[i]));
  }
  while(m--) {
    int t, v, col;
    scanf("%d", &t);
    if(t == 1) {
      scanf("%d %d", &v, &col);
      update(1, 0, cntr - 1, pos[v], q[v], (1LL << col));
      c[v] = col;
    } else {
      scanf("%d", &v);
      printf("%d\n", __builtin_popcountll(find(1, 0, cntr - 1, pos[v], q[v])));
    }
  }
  return 0;
}
