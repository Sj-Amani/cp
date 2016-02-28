#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

char s[N];
int lef[N << 2], rig[N << 2], a[N << 2], good[N << 2];

void gather(int p, int l, int r) {
  if(good[p + p] && good[p + p + 1]) {
    good[p] = 1;
    a[p] = a[p + p] + a[p + p + 1];
  } else if(good[p + p] && !good[p + p + 1]) {
    good[p] = 0;
    lef[p] = a[p + p] + lef[p + p + 1];
    rig[p] = rig[p + p + 1];
    a[p] = a[p + p + 1];
  } else if(!good[p + p] && good[p + p + 1]) {
    good[p] = 0;
    lef[p] = lef[p + p];
    rig[p] = rig[p + p] + a[p + p + 1];
    a[p] = a[p + p];
  } else {
    good[p] = 0;
    lef[p] = lef[p + p];
    rig[p] = rig[p + p + 1];
    a[p] = a[p + p] + a[p + p + 1] + (rig[p + p] + lef[p + p + 1]? rig[p + p] + lef[p + p + 1] - 1 : 0);
  }
}

void build(int p, int l, int r) {
  if(l == r) {
    good[p] = s[l] == '.';
    a[p] = s[l] == '.';
    return;
  }
  int mid = (l + r) >> 1;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  gather(p, l, r);
}

void update(int p, int l, int r, int at, char c) {
  if(l == r) {
    s[l] = c;
    good[p] = s[l] == '.';
    a[p] = s[l] == '.';
    return;
  }
  int mid = (l + r) >> 1;
  if(at <= mid) update(p + p, l, mid, at, c);
  else update(p + p + 1, mid + 1, r, at, c);
  gather(p, l, r);
}

int get() {
  return good[1]? a[1] - 1 : (a[1] + (lef[1]? lef[1] - 1 : 0) + (rig[1]? rig[1] - 1 : 0));
}

int main() {
  int n, q;
  scanf("%d %d %s", &n, &q, s);
  build(1, 0, n - 1);
  while(q--) {
    int at; char c;
    scanf("%d %c", &at, &c);
    update(1, 0, n - 1, at - 1, c);
    printf("%d\n", get());
  }
  return 0;
}
