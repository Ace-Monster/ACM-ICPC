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
const int maxn = 1000005;
int a, b, p;
void Out(int ta, int tb, int n, int k){
	for(int i = 1;i <= n;i++){
		if(ta > k) ta -= k;
		if(tb > k) tb -= k;
		printf("%d %d%c", ta, tb, i == n ? '\n':' ');
		ta = ta+2;
		tb = tb+2;
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    p = 1;
	int n,m;
	scanf("%d%d", &n, &m);
	while(m--){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int x;
			scanf("%d", &x);
			x %= n;
			a = (a+x)%n;
			b = (b+x)%n;
			p = (p+abs(x))%2;
		}
		if(op == 2){
			if(p){
				a++,b--;
			}
			else{
				a--,b++;
			}
			p = !p;
		}
		//dd(a),dd(b),de(p);
	}
	int ta, tb;
	//dd(a),de(b);
	if(a >= 0){
		ta = a/2;
		ta = n - (2*ta-1);
	}
	else{
		ta = -(a-1)/2;
		ta = 1 + 2*ta;
	}
	if(b >= 0){
		tb = (b+1)/2;
		tb = n - 2*(tb-1);
	}
	else{
		tb = -b/2;
		tb = 1 + (2*(tb+1)-1);
	}
	//dd(ta),de(tb);
	if(p){
		Out(ta, tb, n>>1, n);
	}
	else{
		Out(tb, ta, n>>1, n);
	}
	return 0;
}
