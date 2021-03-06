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
const int logn = (log(maxn)/log(2))+1;
const double eps = 1e-9;
int st[maxn+5][logn+5];
int a[maxn+5];
void makest(int n){
	for(int i = 1;i <= n;i++) st[i][0] = a[i];
	for(int j = 1;(1<<j) <= n;j++)
		for(int i = 1;i+(1<<j)-1 <= n;i++)
			st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	int k = log(r-l+1)/log(2)+eps;
	return max(st[l][k], st[r-(1<<k)+1][k]);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i = 1;i <= n;i++)
			scanf("%d", &a[i]);
		makest(n);
		int q;
		scanf("%d", &q);
		while(q--){
			int l,r;
			scanf("%d%d", &l, &r);
			printf("%d\n", query(l,r));
		}
	}
	return 0;
}
