#include<iostream>
#include<cstdio>
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
const int MAXN = 1000000;
char s[MAXN+5];
int kmp[MAXN];
void getkmp(int n){
	kmp[0] = -1;
	for(int i = 1;i < n;i++){
		int j = kmp[i-1];
		while(s[j+1] != s[i] && j >= 0)
			j = kmp[j];
		if(s[j+1] == s[i])
			kmp[i] = j+1;
		else
			kmp[i] = -1;
	}
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	while(~scanf("%s", s)){
		if(s[0] == '.') break;
		int n = strlen(s);
		getkmp(n);
		int len = n-kmp[n-1]-1;
		if(n%len == 0)
			printf("%d\n", n/len);
		else
			printf("%d\n", 1);
	}
	return 0;
}

