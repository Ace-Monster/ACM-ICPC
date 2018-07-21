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
#define be begin
#define en end
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int a[400005];
vi prime;
void Prime(int N)
{
	int cnt = 0;
	bool tag[N];
	memset(tag, 0, sizeof(tag));
	tag[0] = tag[1] = true;
	for(int i = 2;i < N;i++){
		if(!tag[i])
			prime.pb(i), cnt++;
		for(int j = 0;j < cnt && prime[j]*i < N;j++){
			tag[i*prime[j]] = true;
			if(i % prime[j] == 0)break;
		}
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int T;
	while(T--){
		int n,m;
		cin >> n >> m;
		rep(i, 1, n)
			a[i] = i;
		while(m--){
			int t, x, y, p;
			cin >> t >> x >> y;
			switch(t){
				case 1:
					cin >> p;
					vi pi;
					vi::iterator it = prime.begin();
					for(;it != prime.end();it++){
						if((*it)*(*it) > p) break;
						if(p%(*it)) pi.pb(*it);
						while(p%(*it)) p /= (*it);
					}
					ll sum = n*(n+1)/2;
					break;
				case 2:a[x] = c;
			}
		}
	}
	return 0;
}
