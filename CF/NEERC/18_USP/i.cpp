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
int sum, cnt = 0, k;
void hanoi(int n,char A,char B,char C){
	if(n > 1)
		hanoi(n-1, A, C, B);
	if(++cnt == sum){
		int tA = A,tB = B;
		for(int i = sum;i < k;i++){
			printf("%c %c\n", tA, tB);
			swap(tA,tB);
		}
		printf("%c %c\n", tA, C);
	}
	else
		printf("%c %c\n", A, C);
	if(n > 1)
		hanoi(n-1, B, A, C);
}
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n;
	scanf("%d%d", &n, &k);
	sum = (1<<n)-1;
	if(sum > k)
		puts("N");
	else{
		puts("Y");
		hanoi(n,'A','B','C');
	}
	//cout << k << endl;
	return 0;
}
