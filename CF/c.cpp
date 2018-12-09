#include<iostream>
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
const int maxn = 3000+5;
struct A{
	int p,c,flag;
	A() { }
	A(int a,int b,int c): p(a),c(b),flag(c) { }
	bool operator<(const A &x) const{
		return c < x.c;
	}
}vote[maxn];
int flag[maxn],ni[maxn];
set<A> q[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,m;
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &vote[i].p, &vote[i].c);
	}
	sort(vote+1,vote+1+n);
	for(int i = 1;i <= n;i++){
		if(vote[i].p != 1)
			q[vote[i].p].insert(A(vote[i].p,vote[i].c,i));
		ni[vote[i].p]++;
	}
	ll sum = 0x3f3f3f3f3f3f3f3f;
	for(int i = ni[1];i <= n;i++){
		if(i == 0)
			continue;
		int ti = ni[1];
		memset(flag, 0, sizeof flag);
		ll tsum = 0;
		for(int j = 2;j <= m;j++){
			int tn = ni[j]-i;
			set<A>::iterator it = q[j].begin();
			while(tn >= 0){
				tsum += it->c;
				flag[it->flag] = 1;
				it++,++ti,--tn;
			}
		}
		int j = 1;
		while(i > ti){
			if(!flag[j] && vote[j].p != 1)
				tsum += vote[j].c,++ti;
			++j;
		}
		sum = min(sum,tsum);
	}
	printf("%lld\n", sum);
	return 0;
}
