#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
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
	bool tag[1000];
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
	vi::iterator it = prime.begin();
	for(;it != prime.end();it++)
	{
		if (x < *it) return false;
		if (x == *it) return true;
	}
	return false;
}
int n;
void dfs(int a, int m[], int t, vi e){
	e.pb(a);
	if(t == n && find(1+a)) {
		vi::iterator it = e.begin();
		cout << *it;
		it++;
		for (;it != e.end();it++)
			cout << ' ' << *it;
		cout << endl;
		return;
	}
	m[a] = 1;
	rep(i, 2, n + 1)
	{
		if(m[i] == 0 && find(i+a)){
			dfs(i, m, t+1, e);
		}
	}
	m[a] = 0;
	return;
}
int M[25];
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	Prime(400);
	M[1] = 1;
	vector<int> e;
	int t = 0;
	while(cin >> n){
		cout << "Case " << ++t << ':' << endl;
		dfs(1, M, 1, e);
		cout << endl;
	}
	return 0;
}
