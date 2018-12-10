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
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int INF = 32768;
const int maxn = (1<<16)+10;
bool flag[maxn<<2];
int lay[maxn<<2],num[maxn<<2];
void pushup(int rt){
	if(flag[rt<<1] == 1 && flag[rt<<1|1] == 1 && num[rt<<1] == num[rt<<1|1])
		flag[rt] = 1,num[rt] = num[rt<<1];
	else
		flag[rt] = 0;
}
void pushdown(int rt){
	if(lay[rt] != 0){
		lay[rt<<1] = lay[rt<<1|1] = lay[rt];
		num[rt<<1] = num[rt<<1|1] = lay[rt];
		flag[rt<<1] = flag[rt<<1|1] = 1;
		lay[rt] = 0;
	}
}
void update(int t,int L,int R, int l,int r,int rt){
	if(L <= l && r <= R){
		lay[rt] = t;
		num[rt] = t;
		flag[rt] = 1;
		return;
	}
	pushdown(rt);
	int mid = (l+r)>>1;
	if(L <= mid) update(t,L,R,lson);
	if(R >= mid+1) update(t,L,R,rson);
	pushup(rt);
}
int L = -INF,R = INF-1;
void query(int l,int r,int rt){
	pushdown(rt);
	int mid = (l+r)>>1;
	if(flag[rt<<1] == 1 && flag[rt<<1|1] == 0){
		R = mid-INF-1;
		printf("x >= %d && x <= %d ||\n", L, R);
		L = R;
	}
	if(flag[rt<<1] == 0 && flag[rt<<1|1] == 1)
		L = l-INF-1;
	if(flag[rt<<1] != 1) query(lson);
	if(flag[rt<<1|1] != 1) query(rson);
}
void solve(){
	if(flag[1] == 1 && num[1] == 1)
		puts("true");
	else if(flag[1] == 1 && num[1] == 0)
		puts("false");
	else
		query(1,maxn,1);
}
string s;
int l,r;
void dis(int p){
	int ans = 0;
	for(int i = p+3;s[i] <= '9' && s[i] >= '0';i++)
		ans = ans*10+(s[i]-'0');
	if(s[p] == '<')
		r = ans;
	else
		l = ans;
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	memset(flag, true, sizeof flag);
	while(getline(cin, s)){
		int ls = s.size();
		l = -INF+1, r = INF;
		if(ls <= 9){
			dis(2);
		}
		else{
			dis(2);
			for(int i = 3;i <= ls;i++)
				if(s[i] == '<' || s[i] == '>')
					dis(i);
		}
		if(l > r)
			continue;
		dd(l),de(r);
		dd(l+INF),de(r+INF);
		update(1, l+INF, r+INF, 1, maxn, 1);
	}
	solve();
	return 0;
}
