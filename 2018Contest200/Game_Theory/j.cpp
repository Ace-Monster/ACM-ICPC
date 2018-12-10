#include<iostream>
#include<cstdio>
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
int s[105],sg[10005];
bool sets[10005];
void SG(int n){
	sg[0] = 0;
	rep(i,1,10002){
		if(i < s[0]){
			sg[i] = 0;
			continue;
		}
		memset(sets, 0, sizeof(sets));
		rep(j, 0, n){
			if(i-s[j] < 0)
				break;
			sets[sg[i-s[j]]] = 1;
		}
		for(int j = 0;j < 10002;j++){
			if(sets[j] == false){
				sg[i] = j;
				break;
			}
		}
	}
}
int main()
{
	int k;
	while(scanf("%d", &k)){
		if(k == 0)break;
		rep(i, 0, k)
			scanf("%d", &s[i]);
		sort(s, s+k);
		SG(k);
		int m;
		cin >> m;
		rep(i, 0, m){
			int I;
			scanf("%d", &I);
			int ans = 0;
			rep(j, 0, I){
				int t;
				scanf("%d", &t);
				ans^=sg[t];
			}
			if(ans == 0)
				printf("L");
			else
				printf("W");
		}
		printf("\n");
	}
	return 0;
}
