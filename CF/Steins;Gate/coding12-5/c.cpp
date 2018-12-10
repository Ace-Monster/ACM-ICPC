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
const int maxn = 2005;
int a[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	printf("%d\n", n+1);
	rep(i, 0, n){
		scanf("%d", &a[i]);
	}
	ll sum = 0;
	for(int i = n-1;i >= 0;i--){
		int t = (a[i]+sum)%n;
		if(t <= i) t = i-t;
		else t = (n-t)+i;
		printf("1 %d %d\n", i+1, t);
		sum += t;
	}
	printf("2 %d %d\n", n, n);
	return 0;
}
