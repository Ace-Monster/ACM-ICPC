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
vi q;
map<int,int> p;
int LOG(int n,bool &flag){
	int sum = 0;
	while(n){
		if(n != 1 && (n&1) && !flag) flag = true;
		if(n != 1)sum++;
		n>>=1;
	}
	if(flag)
		sum++;
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d", &n);
	int tn = n;
	for(int i = 2;i*i <= n;i++){
		if(n%i == 0){
			q.pb(i);
			while(n%i == 0){
				p[i]++;
				n/=i;
			}
		}
	}
	if(n > 1){
		q.pb(n);
		p[n]++;
	}
	bool flag = false;
	int ans1 = 1,ans2 = -1;
	for(auto i : q){
		ans1 *= i;
		bool tflag = false;
		int t = LOG(p[i],tflag);
		if(tflag || (ans2 != -1 && t != ans2) || t == 0)
			flag = true;
		ans2 = max(ans2, t);
	}
	if(flag) ans2 += 1;
	if(tn == ans1) ans2 = 0;
	printf("%d %d\n", ans1, ans2);
	return 0;
}
