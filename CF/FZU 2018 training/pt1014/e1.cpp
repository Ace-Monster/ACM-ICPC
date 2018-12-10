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
const int maxn = 500005;
char s[maxn], s1[maxn];
stack<char> q, q1;
int main()
{
	//std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
	int n,k,p;
	scanf("%d%d%d", &n, &k, &p);
	scanf("%s", s+1);
	for(int i = 1;i <= p;i++)
		q.push(s[i]);
	for(int i = n;i > p;i--)
		q1.push(s[i]);
	scanf("%s", s1+1);
	for(int i = 1;i <= k;i++){
		if(s1[i] == 'L'){
			q1.push(q.top());
			q.pop();
		}
		if(s1[i] == 'R'){
			q.push(q1.top());
			q1.pop();
		}
		if(s1[i] == 'D'){
			if(q.top() == ')'){
				int ans = 1;
				q.pop();
				while(ans > 0){
					if(q.top() == ')')
						ans++;
					else
						ans--;
					q.pop();
				}
			}
			else{
				int ans = 1;
				q.pop();
				while(ans > 0){
					if(q1.top() == '(')
						ans++;
					else
						ans--;
					q1.pop();
				}
			}
			if(q1.size()){
				q.push(q1.top());
				q1.pop();
			}
		}
		//de(i);
	}
	int l1 = q.size(), l2 = q1.size();
	//dd(l1), de(l2);
	for(int i = l1;q.size();i--){
		s[i] = q.top();
		//de(s[i]);
		q.pop();
	}
	for(int i = l1+1;q1.size();i++){
		s[i] = q1.top();
		//de(s[i]);
		q1.pop();
	}
	s[l1+l2+1] = '\0';
	printf("%s\n", s+1);
	return 0;
}
