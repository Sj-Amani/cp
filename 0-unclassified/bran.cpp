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
const int N = 1e5 + 5;
 
int gcd(int a, int b) { return b? gcd(b, a%b): a; }
int lcm(int a, int b) { return a/ gcd(a, b)*b; }
 
int n, k, ans, bran[105];
vector<int> level[N];
 
int main(void)
{
	int i, j, l;
	sf("%d", &n);
	while(n--) {
		sf("%d", &k);
		FORS(i, k) sf("%d", &bran[i]);
		sort(bran, bran + k);
		FORS(i, k) {
			int found = 0;
			FORD(j, ans, 1) {
				if(level[j].size())
					FORS(l, level[j].size())
						if(bran[i] > level[j][l]) {
							found = j;
							break;
						}
				if(found) break;
			}
			level[found+1].push_back(bran[i]);
			if(found + 1 > ans)
				ans = found + 1;
		}
	}
	cout << ans << endl;
	return 0;
}