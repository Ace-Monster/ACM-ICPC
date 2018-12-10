#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 200005;
int a[maxn<<2],b[maxn],c[maxn];
int ls[maxn<<2], la[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &ls[i]);
		la[i] = ls[i];
	}
	scanf("%d", &m);
	for(int i = 1;i <= m;i++){
		scanf("%d", &ls[n+i]);
		b[i] = ls[n+i];
	}
	for(int i = 1;i <= m;i++){
		scanf("%d", &ls[n+m+i]);
		c[i] = ls[n+m+i];
	}
	sort(ls+1, ls+n+m+m+1);
	int l = unique(ls+1, ls+n+m+m+1) - (ls+1);
	for(int i = 1;i <= n;i++){
		int x = lower_bound(ls+1, ls+l+1, la[i]) - ls - 1;
		a[x]++;
	}
	int ans = 1, sum1 = 0, sum2 = 0;
	for(int i = 1;i <= m;i++){
		int x = lower_bound(ls+1, ls+l+1, b[i]) - ls - 1;
		int y = lower_bound(ls+1, ls+l+1, c[i]) - ls - 1;
		if(a[x] > sum1) sum1 = a[x], sum2 = a[y], ans = i;
		else if(a[x] == sum1 && a[y] > sum2) sum2 = a[y], ans = i;
	}
	printf("%d\n", ans);
	return 0;
}
