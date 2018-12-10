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
const int maxn = 105;
int a[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &a[i]);
	}
	int maxx = 0,p = 1;
	a[0] = 0,a[n+1] = 1001;
	for(int i = 1;i <= n+1;i++){
		if(a[i] - a[i-1] == 1)
			p++;
		else{
			maxx = max(maxx,p);
			p = 1;
		}
	}
	maxx = max(maxx,p);
	int ans = 0;
	if(maxx >= 2) ans = maxx-2;
	printf("%d\n", ans);
	return 0;
}
