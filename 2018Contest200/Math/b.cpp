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
#define be begin
#define en end
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<pair<ll, ll> > q;
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	ll x, y;
	cin >> x >> y;
	string s;
	cin >> s;
	if(x == 0 && y == 0)
		return cout << "Yes" << endl, 0;
	ll n = s.size();
	pair<ll, ll> t(0, 0);
	q.pb(t);
	rep(i, 0, n){
		switch(s[i]){
			case'U':t.se++;
					break;
			case'D':t.se--;
					break;
			case'L':t.fi--;
					break;
			case'R':t.fi++;
					break;
		}
		q.pb(t);
	}
	vector<pair<ll, ll> >::iterator it;
	//for(it = q.be(); it != q.en();it++)
	//	cout << (*it).fi << ' ' << (*it).se << endl;
	if(t.fi == 0)
		for(it = q.be(); it != q.en();)
			if((*it).fi != x)
				it = q.erase(it);
			else
				it++;
	if(t.se == 0)
		for(it = q.be();it != q.en();)
			if((*it).se != y)
				it = q.erase(it);
			else
				it++;
	////cout << endl;
	//for(it = q.be(); it != q.en();it++)
	//	cout << (*it).fi << ' ' << (*it).se << endl;
	if(q.empty())
		return cout << "No" << endl, 0;
	for(it = q.be();it != q.en();it++){
		ll xi = x, yi = y;
		ll kx = 0, ky = 0;
		if(t.fi != 0){
			ll tt = (xi - (*it).fi);
			kx = tt/t.fi;
			xi = tt%t.fi + (*it).fi;
		}
		if(t.se != 0){
			ll tt = (yi - (*it).se);
			ky = tt/t.se;
			yi = tt%t.se + (*it).se;
		}
		if(kx < 0 || ky < 0)
			continue;
		if(t.fi == 0)kx = ky;
		if(t.se == 0)ky = kx;
		if(kx == ky && (*it).fi == xi && (*it).se == yi)
			return cout << "Yes" << endl, 0;
	}
	cout << "No" << endl;
	return 0;
}
