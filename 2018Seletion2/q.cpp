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
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	scanf("%d", &T);
	while(T--){
		ll w,h,r,x,y,vx,vy,t;
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &w, &h, &r, &x, &y, &vx, &vy, &t);
		w -= 2*r, h-=2*r;
		x -= r, y-=r;
		if(w != 0){
			x += vx*t;
			x = abs(x);
			x %= 2*w;
			//dd(x),de(w);
			if(x > w) x = w-(x-w);
		}
		if(h != 0){
			y += vy*t;
			y = abs(y);
			y %= 2*h;
			//dd(y),de(h);
			if(y > h) y = h-(y-h);
		}
		printf("%.2lf %.2lf\n", (double)x+r, (double)y+r);
	}
	return 0;
}
