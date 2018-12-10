#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stack>
#include<cstdio>
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
bool f(char a) {
	if (a == '[' || a == '(' || a == '{' || a == '<')
		return true;
	else
		return false;
}
bool d(char a, char b)
{
	if (a == '{' && b == '}') return true;
	if (a == '[' && b == ']')return true;
	if (a == '<' && b == '>')return true;
	if (a == '(' && b == ')')return true;
	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	stack<char> q;
	char s[1000005];
	scanf("%s", s);
	int l = strlen(s);
	int sum = 0;
	for (int i = 0;i < l;i++) {
		if (f(s[i])) q.push(s[i]);
		else {
			if (q.empty())
				return cout << "Impossible" << endl, 0;
			char t = q.top();
			q.pop();
			if (!d(t, s[i])) sum++;
		}
	}
	if (q.size())
		cout << "Impossible" << endl;
	else
		cout << sum << endl;
	return 0;
}
