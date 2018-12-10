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
const int maxn = 100005;
int a[maxn<<1];
int c[maxn<<1];
int lowbit(int x){
	return	x & (-x);
}
void update(int n, int x, int d){
	while(x <= n) {
        c[x] = c[x] - d;
        x=x + lowbit(x);
	//	dd(x), de(n);
	}
}
int query(int x){
	int res = 0;
	while(x > 0){
		res+=c[x];
		x = x-lowbit(x);
	}
	return res;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n1,n2;
	scanf("%d%d", &n1, &n2);
	int cnt = 0;
	for(int i = n1;i > 0;i--){
		int x;
		scanf("%d", &x);
		a[x] = i;
		update(n1+n2, i, -1);
	}
	for(int i = n1+1;i <= n1+n2;i++){
		int x;
		scanf("%d", &x);
		a[x] = i;
		update(n1+n2, i, -1);
	}
	//sort(a+1, a+n1+n2+1);
	cnt = n1;
	ll sum = 0;
	for(int i = n1+n2;i >= 1;i--){
		int t = query(a[i]) - query(cnt);
		if(t > 0) t--;
		else t = -t;
		sum += t;
		cnt = a[i]-1;
		update(n1+n2, a[i], 1);
	}
	printf("%lld\n", sum);
	return 0;
}
