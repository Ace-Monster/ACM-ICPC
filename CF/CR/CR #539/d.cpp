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
const ll mod = 1e9;
char s[maxn];
map<char, int> q;
bool equ(int i, int n){
	rep(j, 0, n){
		if(s[j] != s[i+j])
			return false;
	}
	return true;
}
bool hw(int i,int n){
	n += i-1;
	rep(j, i, n){
		//dd(i),dd(s[j]),de(s[n-(j-i)]);
		//dd(j),de(n-(j-i));
		if(s[j] != s[n-(j-i)])
			return false;
	}
	return true;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	scanf("%s", s);
	int n = strlen(s);
	rep(i, 0, n){
		s[n+i] = s[i];
		q[s[i]]++;
	}
	if(sz(q) == 1 || (sz(q) == 2 && q[s[n/2]] == 1)){
		puts("Impossible");
		return 0;
	}
	rep(i, 1, n){
		if(equ(i, n)) continue;
		if(hw(i, n)){
			//de(i);
			puts("1");
			return 0;
		}
	}
	puts("2");
	return 0;
}


