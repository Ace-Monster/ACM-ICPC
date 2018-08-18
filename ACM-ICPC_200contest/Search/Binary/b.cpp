#include<iostream>
#include<vector>
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

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	string s;
	cin >> s;
	ll a = 0,b = 0,c = 0;
	int L = s.size();
	rep(i, 0, L){
		if(s[i] == 'C') c++;
		if(s[i] == 'B') b++;
		if(s[i] == 'S') a++;
	}
	ll ap,bp,cp,an,bn,cn;
	cin >> bn >> an >> cn >> bp >> ap >> cp;
	ll R;
	cin >> R;
	ll l = 0, r = 2000000000000;
	ll mid = (l+r)/2;
	while(r - l > 1){
		ll cnt = 0;
		ll ta = ((mid*a) - an)*ap;
		ll tb = ((mid*b) - bn)*bp;
		ll tc = ((mid*c) - cn)*cp;
		if(ta < 0)ta = 0;
		if(tb < 0)tb = 0;
		if(tc < 0)tc = 0;
		cnt = ta+tb+tc;
		if(cnt <= R) l = mid;
		else r = mid;
		mid = (l + r)/2;
	}
	cout << l << endl;
	return 0;
}
