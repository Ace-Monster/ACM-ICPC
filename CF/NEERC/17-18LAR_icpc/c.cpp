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
const int maxk = 1005;
int f[maxk];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int k,n;
	scanf("%d%d", &k, &n);
	for(int i = 1;i <= n;i++){
		int x;
		scanf("%d", &x);
		f[x]++;
	}
	if(n%k == 0){
		int s = n/k;
		int a = 0, b = 0;
		for(int i = 1;i <= k;i++){
			if(f[i] == s) continue;
			if(f[i] > s){
				if(f[i] - s > 1){
					s = 0;break;
				}
				if(a == 0) a = i;
				else{
					s = 0;break;
				}
			}
			if(f[i] < s){
				if(s - f[i] > 1){
					s = 0;break;
				}
				if(b == 0) b = i;
				else{
					s = 0;break;
				}
			}
		}
		if(s != 0 && a != 0 && b != 0){
			printf("-%d +%d\n", a, b);
			return 0;
		}
	}
	if((n+1)%k == 0){
		int s = (n+1)/k;
		int a = 0;
		for(int i = 1;i <= k;i++){
			if(f[i] == s) continue;
			if(f[i] > s){
				s = 0;break;
			}
			if(s-f[i] > 1){
				s = 0;break;
			}
			if(a != 0){
				s = 0;break;
			}
			a = i;
		}
		if(s != 0 && a != 0){
			printf("+%d\n", a);
			return 0;
		}
	}
	if((n-1)%k == 0){
		int s = (n-1)/k;
		int a = 0;
		for(int i = 1;i <= k;i++){
			if(f[i] == s) continue;
			if(f[i] < s){
				s = 0;break;
			}
			if(f[i] - s > 1){
				s = 0;break;
			}
			if(a != 0){
				s = 0;break;
			}
			a = i;
		}
		if(s != 0 && a != 0){
			printf("-%d\n", a);
			return 0;
		}
	}
	printf("*\n");
	return 0;
}
