#include<iostream>
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
struct A{
	int p,d;
	bool operator<(const A &x) const{
		return d > x.d;
	}
}a[10005];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	while(~scanf("%d", &n)){
		rep(i, 0, n){
			scanf("%d%d", &a[i].p, &a[i].d);
		}
		sort(a, a+n);
		priority_queue<int> q;
		int i = 0;
		ll sum = 0;
		for(int d = a[0].d;d > 0;d--){
			while(a[i].d >= d){
				if(i == n) break;
				q.push(a[i++].p);
			}
			if(q.empty()){
				if(i == n) break;
				continue;
			}
			sum += q.top();
			q.pop();
		}
		printf("%lld\n", sum);
	}
	return 0;
}
