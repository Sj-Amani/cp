#include <bits/stdc++.h>

/**
 * Codeforces Round #267 (Div. 2)
 * Problem : B
 * Luqman Arifin (kadalbonek)
 */

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
#define open freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define close fclose(stdin); fclose(stdout)

using namespace std;

const LL mod = 1e9 + 7;
const LL INF = 4e18;
const int inf = 2e9;

int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }

int n, num[1005], cnt;

int main(void)
{
	int i, j, m, k;
	sf("%d %d %d", &n, &m, &k);
	FORS(i, m) {
		sf("%d", num + i);
	}
	int him; sf("%d", &him);
	FORS(i, m) {
		int dif = 0;
		FORS(j, n) {
			if(((1 << j) & him) != ((1 << j) & num[i]))
				dif++;
		}
		if(dif <= k) cnt++;
	}
	cout << cnt << endl;
	return 0;
}
