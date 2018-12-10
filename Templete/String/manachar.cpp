#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(a-1); i>=(b); i--)
#define qrep(i, q) for(auto i : q)
#define sz(a) (int)a.size()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define lowbit(x) x&(-x)
#define all(x) x.begin(),x.end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn = 11000005;
const int inf = 0x3f3f3f3f;
char s[maxn],t[maxn<<1];
int ans[maxn<<1];//以i为中心的回文串长度+1 
int manachar(int l){
	int cnt = 1;
	rep(i, 0, l){
		t[cnt++] = '#';
		t[cnt++] = s[i];
	}
	t[0] = t[cnt++] = '#';
	int mx = 1, id = 1;
	int maxLen = 0;
	rep(i, 1, cnt){
		ans[i] = mx > i ? min(ans[(id<<1)-i], mx-i):1;
		while (t[i+ans[i]] == t[i-ans[i]]) ++ans[i];
		if(i+ans[i] > mx){
			id = i;
			mx = ans[i] + i;
		}
		maxLen = max(maxLen, ans[i]);
	}
	return maxLen-1;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	scanf("%s", s);
	printf("%d", manachar(strlen(s)));
	
	return 0;
}

