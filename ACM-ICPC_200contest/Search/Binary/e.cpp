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
const long double pie = acos(-1.0);
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		long double r,R,h,v;
		cin >> r >> R >> h >> v;
		long double V = (pie*h*(R*R+R*r+r*r))/3;
		long double l1 = 0, r1 = h;
		long double mid = (l1+r1)/2;
		long double dr = R-r;
		while(r1 - l1 > 1e-10){
			if((dr*mid/h)*((dr*mid/h)+3*r) <= 3*((v/pie/mid) - r*r)) l1 = mid;
			else r1 = mid;
			mid = (l1+r1)/2;
		}
		printf("%.6Lf\n", mid);
	}
	return 0;
}
