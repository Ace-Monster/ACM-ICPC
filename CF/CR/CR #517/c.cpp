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
vector<ll> q;
map<int, bool> m;
void p1(ll n, ll ans, ll dn, ll x){
    printf("%lld\n", ans);
    ll cnt = 0;
    for(int i = 1;i <= n;i++){
        if(m[i])
            continue;
        if(cnt)
            printf(" ");
        cnt++;
        printf("%d", i);
    }
    if(!m[dn]) {
        if (cnt)
            printf(" ");
        printf("%lld\n", dn > x ? x : dn);
    }
    else
        printf("\n");
}
void p2(){
    printf("%lu\n", q.size());
    int l = q.size();
    for(int i = 0;i < l;i++)
        printf("%lld%c", q[i], i == l-1 ? '\n':' ');
}
int main()
{
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
    ll a, b;
    cin >> a >> b;
    if(a == 0 && b == 0){
        puts("0\n0\n");
        return 0;
    }
    ll sum = a+b;
    ll n = sqrt(sum);
    while((n+1)*(n+2) < sum*2) n++;
    ll dn = (sum-n*(n+1)/2);
    if(dn <= n) dn += n, n--;
    ll ans = n+1;
    ll ta = a, tb = b;
    if(ta > tb) swap(ta, tb);
    if(ta >= dn){
        q.pb(dn);
        m[dn] = 1;
        ta-=dn;
    }
    while(ta && n > 0){
        if(ta >= n){
            q.pb(n);
            ta -= n;
            n--;
        }
        else{
            q.pb(ta);
            m[ta] = 1;
            ta = 0;
        }
    }
    if(a > b){
        p1(n, ans-q.size(), dn, a);
        p2();
    }
    else{
        p2();
        p1(n, ans-q.size(), dn, b);
    }
    return 0;
}
