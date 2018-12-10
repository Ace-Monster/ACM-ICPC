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
const int maxn = 5000005;
char s[maxn], s1[maxn];
int a[maxn];
stack<int> q;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,k,p;
	scanf("%d%d%d", &n, &k, &p);
	scanf("%s", s+1);
	for(int i = 1;i <= n;i++){
		if(s[i] == '(')
			q.push(i);
		else{
			a[i] = q.top(), a[q.top()] = i;
			q.pop();
		}
	}
	//if(q.size()) puts("1");
	scanf("%s", s1+1);
	int tn = n;
	for(int i = 1;i <= k;i++){
		if(s1[i] == 'R'){
			p++;
			if(s[p] == '+') p = a[p]-1;
			while(s[p] == '+'){
				a[a[p-1]] = a[p];
				p = a[p]+1;
			}
		}
		if(s1[i] == 'L'){
			p--;
			if(s[p] == '-') p = a[p]-1;
			while(s[p] == '-'){
				a[a[p+1]] = a[p];
				p = a[p]-1;
			}
		}
		if(s1[i] == 'D'){
			int l = p, r = a[p];
			if(l > r) swap(l, r);
			s[l] = '+', s[r] = '-';
			while(s[p] == '-') {
				p++;
			}
			if(s[p] == '+') p = a[p]+1;
			while(s[p] == '+') {
				a[a[p-1]] = a[p];
				p = a[p] + 1;
			}
			if(p > tn){
				p = tn;
				while(s[p] == '-')
					p = a[p] - 1;
				tn = p;
			}
			printf("%s\n", s+1);
		}
		de(p);
		if(p > tn || p <= 0 || (s[p] != '(' && s[p] != ')'))
			puts("1");
	}
	//printf("%s\n", s+1);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(s[i] == '+') {
			i = a[i];
			continue;
		}
		if(ans == 0)
			printf("%c", s[i]);
	}
	printf("\n");
	return 0;
}

