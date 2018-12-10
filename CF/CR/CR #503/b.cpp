#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
#include<functional>
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
const int maxn = 1000+10;
int flag[maxn],p[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++)
		scanf("%d", &p[i]);
	for(int i = 1;i <= n;i++){
		memset(flag, 0, sizeof flag);
		int t = i;
		while(!flag[t]){
			flag[t]++;
			t = p[t];
		}
		printf("%d%c", t, i == n ? '\n':' ');
	}
	return 0;
}
