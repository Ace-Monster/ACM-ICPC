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
const int maxn = 5005;
int f[maxn], next[maxn];
char s[maxn],b[maxn];
void fnext(int l, int n){
	f[1] = 0;
	for(int i = 2;i <= n;i++){
		int j = f[i-1];
		while(b[l+j+1] != b[l+i] && j > 0)
			j = f[j];
		if(b[l+j+1] == b[l+i])
			f[i] = j+1;
		else
			f[i] = 0;
	}
}
int main()
{
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
	scanf("%s", b+1);
	int l = strlen(b+1);
	int sum = 0;
	for(int i = 0;i < l;i++){
		fnext(i, l-i);
		for(int j = 1;j <= l-i;j++){
			if(j%(j-f[j]) != 0 || j-f[j] == j){
				sum++;
			}
		}
	}
	printf("%d\n", sum);
	return 0;
}
