#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<functional>
#include<stack>
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
const int maxn = 1000005;
char a[maxn],b[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	scanf("%s", a+1);
	scanf("%s", b+1);
	ll ans = 0;
	for(int i = 1;i < n;i++){
		if(a[i] != b[i]){
			if(a[i+1] != b[i+1] && a[i] != a[i+1]){
				ans++;swap(a[i], a[i+1]);
			}
			else
				ans++;a[i] = b[i];
		}
	}
	if(a[n] != b[n]) ans++;
	printf("%lld\n", ans);
	return 0;
}
