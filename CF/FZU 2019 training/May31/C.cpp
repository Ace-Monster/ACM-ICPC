#include<bits/stdc++.h>
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
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 100005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9;
ld d[maxn], l;
ld cal(ld ax, ld ay, ld bx, ld by){
	ld dx = bx-ax, dy = by-ay;
	return sqrt(dx*dx+dy*dy);
}
struct A{
	int id;
	ld d, kd;
	bool operator<(const A &x) const{
		if(kd == x.kd) return id < x.id;
		else return kd < x.kd;
	}
}ad[maxn],bd[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    
	ld ax,bx,ay,by,tx,ty;
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	int n;
	cin >> n;
	ld ta = cal(ax, ay, tx, ty);
	ld tb = cal(bx, by, tx, ty);
	rep(i, 0, n){
		ld xi, yi;
		cin >> xi >> yi;
		d[i] = cal(xi, yi, tx, ty);
		l += 2.0*d[i];
		ad[i].id = bd[i].id = i;
		ad[i].d = cal(ax, ay, xi, yi);
		bd[i].d = cal(bx, by, xi, yi);
		//dd(d[i]),dd(ad[i].d),de(bd[i].d);
	}
	rep(i, 0, n){
		ad[i].kd = ad[i].d+l-d[i];
		bd[i].kd = bd[i].d+l-d[i];
	}
	ld ans = min(ta+l, tb+l);
	sort(ad, ad+n);
	sort(bd, bd+n);
	ans = min(ans, ad[0].kd);
	ans = min(ans, bd[0].kd);
	rep(i, 0, 2){
		rep(j, 0, n){
			if(bd[j].id == ad[i].id) continue;
			ans = min(ans, ad[i].kd + (bd[j].d-d[bd[j].id]));
		}
	}
	rep(i, 0, 2){
		rep(j, 0, n){
			if(bd[i].id == ad[j].id) continue;
			ans = min(ans, bd[i].kd + (ad[j].d-d[ad[j].id]));
		}
	}
	//cout << ans << endl;
	printf("%.10Lf", ans);
	return 0;
}


