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
const int maxn = 100005;
char s[maxn];
bool check(char x){
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	scanf("%s", s);
	int sum = 0, l = strlen(s);
	for(int i = 0;i < l;i++){
		if(check(s[i]))
			sum++;
	}
	if(sum == 0 || sum == l)
		puts("1");
	else{
		if(!check(s[0]))
			puts("0");
		else if(sum == l-1 || sum == 1)
			printf("%d\n", l);
		else{
			int x = sum/2;
			if(sum%2) x++;
			int l = -1,r = -1;
			while(x){
				r++;
				if(check(s[r]))
					x--;
			}
			l = r;
			for(r++;!check(s[r]);r++);
			//dd(l),de(r);
			printf("%d\n", r-l);
		}
	}
	return 0;
}
