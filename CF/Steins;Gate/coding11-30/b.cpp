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
bool f(int n){
	int a = 0,b = 0;
	while(n){
		if(n%2 == 1)
			break;
		a++;
		n>>=1;
	}
	while(n){
		if(n%2 == 0)
			break;
		b++;
		n>>=1;
	}
	if(n) return false;
	if(a == b-1)
		return true;
	return false;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	int ans = 1;
	for(int i = 1;i*i <= n;i++){
		if(n%i == 0){
			if(f(i)) ans = max(ans, i);
			if(f(n/i)) ans = max(ans, n/i);
		}
	}
	printf("%d\n", ans);
	return 0;
}
