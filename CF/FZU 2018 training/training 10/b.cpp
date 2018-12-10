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
char s[maxn];
map<char, int> q;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	scanf("%s", s);
	int n = strlen(s);
	for(int i = 0;i < n;i++)
		q[s[i]]++;
	if(q.size() > 4 || q.size() == 1 || (q.size() == 3 && n == 3)){
		puts("NO");
		return 0;
	}
	if(q.size() == 2){
		for(auto i : q)
			if(i.second == 1){
				puts("NO");
				return 0;
			}
	}
	puts("YES");
	return 0;
}
