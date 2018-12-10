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
stack<char> q;
int a[30];
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	string s;
	cin >> s;
	int n = s.size();
	rep(i, 0, n){
		a[s[i]-'a']++;
	}
	int p = 0;
	rep(i, 0, n){
		q.push(s[i]);
		a[s[i]-'a']--;
		while(!a[p])p++;
		while(q.size() && q.top() - 'a' <= p){
			printf("%c", q.top());
			q.pop();
		}
	}
	while(q.size()){
		printf("%c", q.top());
		q.pop();
	}
	printf("\n");
	return 0;
}
