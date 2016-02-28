#include <bits/stdc++.h>

using namespace std;

const int day[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int inf = 1e9;
const int N = 5e6 + 5;

class date {
public:
  date() {
  
  }
  date(int _d, int _m, int _y) : d(_d), m(_m), y(_y) {
    
  }
  bool yesterday(date _date) {
    if(m == _date.m) {
      return _date.d + 1 == d;
    }
    if(_date.m + 1 == m) {
      return _date.d == day[_date.m - 1] && d == 1;
    }
    return 0;
  }
  bool same(date _date) {
    return _date.d == d && _date.m == m && _date.y == y;
  }
  int d, m, y;
};

class hour {
public:
  hour() {
    
  }
  hour(int _h, int _m, int _s) : h(_h), m(_m), s(_s) {
  
  }
  int sec() {
    return h * 3600 + m * 60 + s;
  }
  int h, m, s;
};

class waktu {
public:
  // t <= this, return seconds
  waktu() : tanggal(), jam() {
  
  }
  waktu(int y, int m, int d, int j, int menit, int detik) :
    tanggal(d, m, y), jam(j, menit, detik) {
  }
  int dif(waktu t) {
    if(!tanggal.yesterday(t.tanggal) && !tanggal.same(t.tanggal)) {
      return inf;
    }
    if(tanggal.yesterday(t.tanggal)) {
      return hour(24, 0, 0).sec() - t.jam.sec() + jam.sec();
    }
    return jam.sec() - t.jam.sec();
  }
  void print() {
    int mm = tanggal.m;
    int dd = tanggal.d;
    int ja = jam.h;
    int men = jam.m;
    int det = jam.s;
    printf("%d-%d%d-%d%d %d%d:%d%d:%d%d\n", tanggal.y, mm/10, mm%10, dd/10, dd%10,
    ja/10, ja%10, men/10, men%10, det/10, det%10);
  }
  date tanggal;
  hour jam;
};

char junk[N];
waktu a[N];

int main() {
  int n, m;
  int y, mon, d, jam, menit, detik;
  scanf("%d %d", &n, &m);
  int log = 0;
  while(~scanf("%d-%d-%d %d:%d:%d:", &y, &mon, &d, &jam, &menit, &detik)) {
    gets(junk);
    a[log++] = waktu(y, mon, d, jam, menit, detik);
  }
  int j = 0;
  long long dif = 0;
  for(int i = 1; i < log; i++) {
    dif += a[i].dif(a[i - 1]);
    while(j < i && dif >= n) {
      dif -= a[j + 1].dif(a[j]);
      j++;
    }
    if(i - j + 1 >= m) {
      a[i].print();
      return 0;
    }
  }
  puts("-1");
  return 0;
}
