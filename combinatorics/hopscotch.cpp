#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define pii pair<ll,ll>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(ll i=0;i<n;i++)
#define pb push_back
#define f first
#define s second

const ll MOD = (ll)1e9+7;
ll binpow(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll x = binpow(a,b/2)%MOD;
    x = (x*x)%MOD;
    if(b%2==1) x = (x*(a%MOD))%MOD;
    return x;
}
const ll MAXF = 2e6+10;
ll fact[MAXF];
ll divide(ll a, ll b){
    return ((a%MOD)*(binpow(b,MOD-2)%MOD))%MOD;
}
ll mult(ll a, ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}
ll distribute(ll m, ll n){
    //distribute n objects llo m containers
    //n+m-1 chose m 
    //(m+n-1)!/(m! * (n-1)!)
    ll denom = mult(fact[m],fact[n-1]);
    ll numen = fact[n+m-1];
    //cout<<denom<<" "<<numen<<endl;
    return divide(numen,denom);
}
void precompute(){
    fact[0] = fact[1] = 1;
    for(ll i=2;i<MAXF;i++){
        fact[i] = mult(fact[i-1],i);
    }
}

int main()
{
    ll n,x,y;
    cin>>n>>x>>y;
    ll maxhops = min(n/x,n/y);
    ll ans = 0;
    precompute();
    for(ll i=1;i<=maxhops;i++){
        ll xl = i*x;
        ll leftx = n-xl;
        ll yl = i*y;
        ll lefty = n-yl;
        //cout<<distribute(leftx,i)<<" "<<distribute(lefty,i)<<endl;
        ans=(ans+distribute(leftx,i)*distribute(lefty,i))%MOD;
    }
    cout<<ans<<endl;
    return 0;
}
