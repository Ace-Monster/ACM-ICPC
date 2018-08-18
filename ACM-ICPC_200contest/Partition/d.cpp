#include<iostream>
#include<vector>
#include<cstdio>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
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
ll a[1005];
struct A{
	int a,b;
	A(int x,int y): a(x),b(y) { }
};
vector<A> q;
ll tc(int n){
	if(n == 1){
		q.pb(A(a[0],0));
		return a[0];
	}
	if(n == 2){
		q.pb(A(a[0],a[1]));
		return a[1];
	}
	if(n == 3){
		q.pb(A(a[0],a[2]));
		q.pb(A(a[0],0));
		q.pb(A(a[0],a[1]));
		return a[0]+a[1]+a[2];
	}
	ll sum = -a[0];
	for(int i = 1;i < n;i++)
		sum += a[i]+a[0];
	int tsum = a[0]+a[1]+a[1]+a[n-1]+tc(n - 2);
	if(sum < tsum){
		q.clear();
		for(int i = 1;i < n;i++){
			q.pb(A(a[0],a[i]));
			if(i != n-1)
				q.pb(A(a[0], 0));
		}
		return sum;
	}
	else{
		q.pb(A(a[0],0));
		q.pb(A(a[n-2],a[n-1]));
		q.pb(A(a[1],0));
		q.pb(A(a[0],a[1]));
		return tsum;
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	rep(i, 0, n)
		cin >> a[i];
	sort(a, a+n);
	printf("%lld\n", tc(n));
	vector<A>::iterator it;
	for(it = q.begin();it != q.end();it++){
		if(it->b != 0)
			printf("%d %d\n", it->a, it->b);
		else
			printf("%d\n",it->a);
	}
	return 0;
}
