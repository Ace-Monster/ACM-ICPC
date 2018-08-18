#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
#include<functional>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define be begin
#define en end
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 1000000;
const double eps = 1e-9;
int a[maxn + 5];
int maxst[maxn + 5][64], minst[maxn + 5][64];
void makest(int n) {
	for (int i = 1;i <= n;i++) maxst[i][0] = a[i], minst[i][0] = a[i];
	for (int j = 1;(1 << j) <= n;j++)
		for (int i = 1;(i + (j << 1) - 1 <= n);i++)
			maxst[i][j] = max(maxst[i][j - 1], maxst[i + (1 << (j - 1))][j - 1]),
			minst[i][j] = min(minst[i][j - 1], minst[i + (1 << (j - 1))][j - 1]);
}
bool query(int l, int r, int k) {
	int K = log(r - l + 1) / log(2) + eps;
	return max(maxst[l][K], maxst[r - (1 << K) + 1][K]) - min(minst[l][K], minst[r - (1 << K) + 1][K]) < k;
}
int main()
{
	//std::ios::sync_with_stdio(false);
	//std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		ll sum = 0;
		scanf("%d%d", &n, &k);
		for (int i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		makest(n);
		for (int i = 1, j = 1;i <= n;) {			
			if (j <= n && query(i, j, k))j++;
			else  sum += (j - i++);
		}
		printf("%lld\n", sum);
	}
	return 0;
}
