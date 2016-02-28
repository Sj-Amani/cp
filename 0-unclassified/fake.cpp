#include <bits/stdc++.h>

typedef long long LL;
typedef double DB;

#define sf scanf
#define pf printf
#define mp make_pair
#define nl printf("\n")

#define FOR(i,a,b) for(i = a; i <= b; ++i)
#define FORD(i,a,b) for(i = a; i >= b; --i)
#define FORS(i,n) for(i = 0; i < n; ++i)
#define FORM(i,n) for(i = n - 1; i >= 0; --i)
#define reset(i,n) memset(i, n, sizeof(i))

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;
const double eps = 1e-13;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

set<string> ada;
char s[1005];

int main(void)
{
	int i, j, n, ans = 0;
	sf("%s", &s[1]);
	n = strlen(&s[1]);
	FOR(i, 1, n) {
		FOR(j, i+1, n) {
			string jadi = "";
			jadi.push_back(s[i]);
			jadi.push_back(s[j]);
			int a, b, c;
			a = i;
			b = j;
			c = i + j;
			while(c <= n) {
				jadi.push_back(s[c]);
				a = b;
				b = c;
				c = a + b;
			}
			ada.insert(jadi);
		}
	}
	cout << ada.size() << endl;
	return 0;
}
