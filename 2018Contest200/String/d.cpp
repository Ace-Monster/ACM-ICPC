#include<iostream>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>
#include<string.h>
#include<queue>
#include<functional>
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
const int MAXN = 100000;
int s[MAXN+5],new_s[2*MAXN+5];
int init(int n){
	new_s[0] = 1;
	new_s[1] = 0;
	int j = 1;
	for(int i = 0;i < n;i++){
		new_s[++j] = s[i];
		new_s[++j] = 0;
	}
	new_s[++j] = -1;
	return j+1;
}
int manachar(int n){
	int l = init(n);
	int id = 0,mx = 0;
	int maxlen = 0;
	int p[2*MAXN+5];
	memset(p, 0, sizeof p);
	for(int i = 1;new_s[i] != -1;i++){
		p[i] = mx > i ? min(p[2*id-i], mx - i) : 1;
		while(new_s[i + p[i]] == new_s[i-p[i]]){
			if(new_s[i+p[i]] != 0)
				if(new_s[i+p[i]] > new_s[i+p[i]-2])
					break;
				else
					p[i]++;
			else
				p[i]++;
		}
		maxlen = max(p[i],maxlen);
		if(i + p[i] > mx){
			mx = i + p[i];
			id = i;
		}
	}
	return maxlen-1;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n;
		scanf("%d", &n);
		for(int i = 0;i < n;i++)
			scanf("%d", &s[i]);
		printf("%d\n", manachar(n));
	}
	return 0;
}
