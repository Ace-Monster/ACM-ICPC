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
const int MAXN = 50000;
const double eps = 1e-9;
int maxst[MAXN+5][32], minst[MAXN+5][32],a[MAXN];
void makest(int n){
	for(int i = 1;i <= n;i++) maxst[i][0] = minst[i][0] = a[i];
	for(int j = 1;(1<<j)<=n;j++)
		for(int i = 1;i+(1<<j)-1 <= n;i++)
			maxst[i][j] = max(maxst[i][j-1], maxst[i+(1<<(j-1))][j-1]),
			minst[i][j] = min(minst[i][j-1], minst[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	int k = log2(r-l+1.0)+eps;
	return max(maxst[l][k], maxst[r-(1<<k)+1][k]) - min(minst[l][k], minst[r-(1<<k)+1][k]);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,q;
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	makest(n);
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		printf("%d\n", query(l,r));
	}
	return 0;
}
