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
char a[1005],b[1005];
int f[1005];
void fnext(int n){
	f[0] = -1;
	for(int i = 1;i < n;i++){
		int j = f[i-1];
		while(b[i] != b[j+1] && j >= 0)
			j = f[j];
		if(b[i] == b[j+1])
			f[i] = j+1;
		else
			f[i] = -1;
	}
}
int find(int n,int m){
	int i = 0,j = 0;
	int sum = 0;
	while(i < n){
		if(a[i] == b[j]){
			i++,j++;
			if(j == m){
				sum++;
				j = 0;
			}
		}
		else{
			if(j == 0)
				i++;
			else
				j = f[j-1]+1;
		}
	}
	return sum;
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	while(~scanf("%s", a)){
		if(a[0] == '#')break;
		scanf("%s", b);
		fnext(strlen(b));
		cout << find(strlen(a),strlen(b)) << endl;
	}
	return 0;
}
