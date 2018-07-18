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
vi prime;
void Prime(int N){
	int cnt = 0;
	bool tag[N];
	memset(tag, 0, sizeof(tag));
	tag[0] = tag[1] = true;
	for(int i = 2;i < N;i++){
		if(!tag[i])
			prime.pb(i), cnt++;
		for(int j = 0;j < cnt && prime[j]*i < N;j++){
			tag[i*prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}
inline bool find(int x){
	return count(prime.begin(), prime.end(), x);
}
int n;
vector<vector<int> > E;
int l = 0;
bool dfs(int a, int m[], int t, vector<int> e){
	e.pb(a);
	if(t == n && find(1+a)) {
		E.pb(e);
		return true;
	}
	m[a] = 1;
	rep(i, 2, n)
	{
		if(m[i] == 0 && find(m[i]+a)){
			dfs(i, m, t+1, e);
		}
	}
	return false;
}
int m[25];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n;
	m[1] = 1;
	vector<int> e;
	e.pb(1);
	int t = 0;
	while(cin >> n){
		dfs(1, m, 2, e);
		cout << "case" << ++t << ':' << endl;
		vector<vector<int> >::iterator it = E.begin();
		for(;it != E.end();it++){
			rep(i, 0, n)
				cout << (*it)[i] <<' ';
			cout << endl;
		}
		cout << endl;
	}
	return 0;
}
