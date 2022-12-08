#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;
set<ll> all;
ll toNumb(string a){
    ll v = 0;
    FOR(i,sz(a)){
        if(a[i]=='1')
            v+=(1LL<<i);
    }
    if(v<=0){
        cout<<a<<endl;
        cout<<sz(a)<<endl;
       cout<<v<<endl;
    }
    assert(v>0);
    return v;
}
void solve(int n, int m, string curr, int i){
    if(curr.size()>63) return;
    if(i%2==0) curr=string(n,'1')+curr;
    else curr=string(m,'0')+curr;
    if(sz(curr)<=63)
    all.insert(toNumb(curr));    

    solve(n,m,curr,i+1);
}
int main()
{
    ll a, b;
    cin>>a>>b;
    for(int i=1;i<=63;i++) for(int j = 1;j<=63;j++){
        solve(i,j,"",0);
    }
    int ans = 0;
    for(ll x: all) if(a<=x && x<=b) ans++;
    cout<<ans<<endl;
    return 0;
}
