#include<cstdio>
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
const int inf = -1;
char s[100005];
int next[100005];
int cnt = 0,p = 0;
int main()
{
	while(~scanf("%s", s+1)){
		int cnt = 0,p = 0;
		int n = strlen(s+1);
		next[0] = 0;
		for(int i = 1;i <= n;i++){
			if(s[i] == '[') p = 0;
			else if(s[i] == ']') p = cnt;
			else{
				next[i] = next[p];
				next[p] = i;
				if(p == cnt) cnt = i;
				p = i;
			}
		}
		for(int i = next[0];i != 0;i = next[i])
			printf("%c", s[i]);
		printf("\n");
	}
	return 0;
}
