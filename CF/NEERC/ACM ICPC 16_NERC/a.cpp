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
queue<string> q;
void display(){
    if(q.size() == 1){
        cout << q.front();
        q.pop();
        return;
    }
    if(q.size() > 1){
        int l = q.size();
        string ans;
        for(int i = 0;i < l;i++){
            string s = q.front();
            q.pop();
            q.push(s);
            s = s[0];
            ans = ans+s;
        }
        cout << ans << " (";
        for(int i = 0;i < l;i++){
            string s = q.front();
            q.pop();
            if(i == l-1) {
                int tl = s.size();
                if(s[tl - 1] <= 'z' && s[tl - 1] >= 'a')
                    s.insert(tl, ")");
                else
                    s.insert(tl - 1, ")");
            }
            cout << s;
        }
    }
}
int main()
{
    //freopen("abbreviation.in", "r", stdin);
    //freopen("abbreviation.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string s;
    while(getline(cin, s)){
        int l = s.size(), i = 0, j = 0;
        while(i < l){
            int sum = 0;
            while(( (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )&& i < l){
                if(s[i] <= 'Z' && s[i] >= 'A') sum++;
                i++;
            }
            if(i < l) i++;
            int tl = i-j;
            if(s[i-1] >= 'a' && s[i-1] <= 'z') tl++;
            if(s[j] > 'Z' || s[j] < 'A' || sum > 1 || tl <= 2){
                display();
                while(j < i)
                    cout << s[j++];
                continue;
            }

            string t;
            while(j < i) t = t+s[j++];
            q.push(t);
            if(s[i-1] != ' ' && (s[i-1] < 'a' || s[i-1] > 'b')) {
                display();
            }
        }
        display();
        cout << endl;
    }
    return 0;
}
