
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
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	long double y;
	long double e = exp(1);
	while(cin >> y){
		long double ty = (1+logl(y))/e/y;
		if(y == 1){
			printf("%.5lf\n", exp(1));
			continue;
		}
		long double l = 0,r = exp(1);
		long double x = (l+r)/2.0;
		while(r - l > 1e-10){
			if(logl(x)/x <= ty) l = x;
			else r = x;
			x = (l+r)/2.0;
		}
		printf("%.5Lf %.5Lf\n", x, e*y);
		/*if(ty > 0){
			l = exp(1), r = 1e11;
			x = (l+r)/2.0;
			while(r - l > 1e-10){
				if(logl(x)/x > ty) l = x;
				else r = x;
				x = (l+r)/2.0;
			}
			printf(" %.5Lf", x);
		}
		printf("\n");
	*/}
	return 0;
}
