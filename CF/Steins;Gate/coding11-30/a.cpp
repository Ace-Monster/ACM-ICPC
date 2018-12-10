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
bool sw(int &a, int &b, int &c){
	if(a == 0){
		puts("NO");
		return 0;
	}
	swap(b,c);
	return 1;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	int a = 1,b = 1,c = 0;
	int k;
	for(int i = 1;i <= n;i++){
		scanf("%d", &k);
		if(k == 1){
			if(!sw(a,b,c))
				return 0;
		}else if(k == 2){
			if(!sw(b,a,c))
				return 0;
		}else if(k == 3){
			if(!sw(c,a,b))
				return 0;
		}
	}
	puts("YES");
	return 0;
}
