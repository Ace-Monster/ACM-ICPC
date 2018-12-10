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
const int maxn = 100005;
int x[maxn];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x[i]);
	}
	x[n+1] = x[1],x[n+2] = x[2];
	for(int i = 3;i <= n+2;i++){
		if(x[i] < x[i-1] && x[i-1] > x[i-2]){
			int a = i-2, b = i-1, c = i;
			if(a > n) a -= n;
			if(b > n) b -= n;
			if(c > n) c -= n;
			printf("%d %d %d\n", a, b, c);
			return 0;
		}
	}
	return 0;
}
