#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
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
const int N = 1005;
vi f;
void fib(){
	f.pb(1), f.pb(1);
	for(int i = 1;f[i] < N;i++){
		f.pb(f[i]+f[i-1]);
	}
	f.erase(f.begin());
}
int sg[N];
void SG(){
	vi::iterator it;
	sg[0] = 0;
	for(int i = 1;i < N;i++){
		set<int> q;
		for(it = f.begin();it != f.end() && *it <= i;it++){
			q.insert( sg[i-(*it)] );
		}
		set<int>::iterator sit = q.begin();
		int t = 0;
		for(;sit != q.end();sit++){
			if(t < *sit) {
				break;
			}
			else
				t = *sit+1;
		}
		sg[i] = t;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	fib();
	SG();
	int m,n,p;
	while(cin >> m >> n >> p){
		if(m == 0 && n == 0 && p == 0) break;
		if ((sg[m] ^ sg[n] ^ sg[p]))
			cout << "Fibo" << endl;
		else
			cout << "Nacci" << endl;
	}
	return 0;
}
