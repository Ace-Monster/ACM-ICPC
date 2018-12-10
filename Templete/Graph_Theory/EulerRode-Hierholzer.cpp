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
const int maxn = 100005;
const int inf = 0x3f3f3f3f;
multiset<int> edge[100];
map<char, int> ls;
map<int, char> sl;
char ans[maxn];
int cnt;
void dfs(int u){
	for(auto i = edge[u].begin();i != edge[u].end();i=edge[u].begin()){
		int v = *i;
		edge[u].erase(i);
		edge[v].erase(edge[v].find(u));
		dfs(v);
	}
	ans[cnt--] = sl[u];
	return;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	for(char i = 'A';i <= 'Z';i++){
		ls[i] = (i-'A'+1);
		sl[i-'A'+1] = i;
	}
	for(char i = 'a';i <= 'z';i++){
		ls[i] = (i-'a'+27);
		sl[i-'a'+27] = i;
	}
	int n;
	cin >> n;
	cnt = n;
	rep(i, 0, n){
		string s;
		cin >> s;
		edge[ls[s[0]]].insert(ls[s[1]]);
		edge[ls[s[1]]].insert(ls[s[0]]);
	}
	//for(auto i:edge[ls['v']]) cout << sl[i] << ' ';
	//cout << endl;
	int t = 0, u = 0, tu = 0;
	rep(i, 1, 53){
		if(sz(edge[i]) && !tu) tu = i;
		if(sz(edge[i])&1){
			t++;
			if(!u) u = i;
		}
	}
	//de(t);
	if(t == 1 || t > 2) return cout << "No Solution" << endl, 0;
	if(u) dfs(u);
	else dfs(tu);
	//de(cnt);
	if(cnt != -1) return cout << "No Solution" << endl, 0;
	ans[n+1] = '\0';
	printf("%s", ans);
	return 0;
}

