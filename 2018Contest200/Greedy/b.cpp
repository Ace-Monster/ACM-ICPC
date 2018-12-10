#include<iostream>
#include<cstdio>
#include<vector>
#include<string.h>
#include<cmath>
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
double a[10005];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	cin >> T;
	const double pie = acos(double(-1));
	while(T--){
		memset(a, 0, sizeof(a));
		int N;
		int F;
		cin >> N >> F;
		F++;
		double sumk = 0;
		rep(i, 0, N){
			cin >> a[i];
			a[i] = a[i]*a[i]*pie;
			sumk += a[i];
		}
		double l = 0, r = sumk/(double)F;
		double mid = (l + r)/2;
		while(r - l > 0.000001){
			int sum = 0;
			rep(i, 0, N){
				if(a[i] > mid){
					sum += (int)(a[i]/mid);
					if(sum > F) break;
				}
			}
			if(sum >= F) l = mid;
			else r = mid;
			mid = (l + r)/2;
		}
		printf("%.5lf\n", l);
	}
	return 0;
}
