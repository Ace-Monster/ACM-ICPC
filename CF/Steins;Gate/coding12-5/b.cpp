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
const int maxn = 100005;
int a[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n, k;
	scanf("%d%d", &n, &k);
	rep(i, 0, n){
		scanf("%d", &a[i]);
	}
	sort(a, a+n);
	int sum = 0;
	int p = 0;
	rep(i, 0, k){
		while(a[p]-sum == 0 && p < n)p++;
		if(p >= n){
			puts("0");
			continue;
		}
		printf("%d\n", a[p]-sum);
		sum = a[p];
	}
	return 0;
}
