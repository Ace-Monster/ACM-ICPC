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
int a[10005];
int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	int l = 0,r = 0;
	rep(i, 0, n){
		double temp;
		scanf("%lf", &temp);
		a[i] = (temp*100);
		r = max(a[i], r);
	}
	int mid = (l+r)/2;
	while(r - l > 1){
		int sum = 0;
		rep(i, 0, n)
			sum+=floor(a[i]/mid);
		if(sum >= m) l = mid;
		else r = mid;
		mid = (l+r)/2;
	}
	double temp = ((double)mid/100.0);
	printf("%.2lf", temp);
	return 0;
}
