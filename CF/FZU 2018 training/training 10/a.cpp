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
typedef pair<int, int> pii;
typedef vector<int> vi;
int ceil(int a,int b){
	int t = a/b;
	if(a%b) t++;
	return t;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int hh,mm;
	scanf("%d%d", &hh, &mm);
	int h,d,c,n;
	scanf("%d%d%d%d", &h, &d, &c, &n);
	double ans = ceil(h, n)*c;
	if(hh < 20){
		h += d*((19-hh)*60 + 60 - mm);
		ans = min(ans, ceil(h, n)*c*0.8);
	}
	else
		ans *= 0.8;
	printf("%.4lf\n", ans);
	return 0;
}
