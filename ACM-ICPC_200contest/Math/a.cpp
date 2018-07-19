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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	const ld eps = 1e-10;
	ld k,d,t;
	cin >> k >> d >> t;
	ld T = ceil(k/d - eps)*d;
	ld s = k+(T-k)/2;
	ld tt = floor(t/s + eps);
	ld sum = T*tt;
	ld su = t - tt*s;
	if(su <= k)
		sum += su;
	else
		sum += k + (su-k)*2;
	printf("%Lf", sum);
	return 0;
}
