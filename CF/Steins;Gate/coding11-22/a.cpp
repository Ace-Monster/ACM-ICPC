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
const int inf = 0x3f3f3f3f;
vi q;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n, k;
	cin >> n >> k;
	for(int i = 2;i*i <= n;i++){
		if(n%i == 0){
			while(n%i == 0 && q.size() < k-1){
				q.pb(i);
				n/=i;
			}
			if(q.size() == k-1){
				break;
			}
		}
	}
	if(n != 1) q.pb(n);
	int cnt = 0;
	if(q.size() == k){
		for(auto i : q){
			printf("%d%c", i, k == ++cnt ? '\n':' ');
		}
	}
	else
		puts("-1");
	return 0;
}
