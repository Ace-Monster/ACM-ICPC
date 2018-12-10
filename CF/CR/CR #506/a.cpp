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
const int maxn = 55;
int f[maxn];
string s;
void fnext(int n){
	f[0] = -1;
	for(int i = 1;i < n;i++){
		int j = f[i-1];
		while(s[j+1] != s[i] && j >= 0)
			j = f[j];
		if(s[j+1] == s[i])
			f[i] = j+1;
		else
			f[i] = -1;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	int n,k;
	cin >> n >> k;
	cin >> s;
	fnext(n);
	string t;
	for(int i = f[n-1]+1;i < n;i++)
		t = t+s[i];
	for(int i = 1;i < k;i++)
		s = s+t;
	cout << s << endl;
	return 0;
}
