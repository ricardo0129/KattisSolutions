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

struct frac{
    typedef frac F;
    ll numerator, denomerator;
    frac(ll a, ll b){
        assert(b!=0);
        numerator = a;
        denomerator = b;
    }
};

ll binpow(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll x = binpow(a,b/2)%MOD;
    x = (x*x)%MOD;
    if(b%2==1) x = ((x%MOD)*(a%MOD))%MOD;
    return x;
}
ll divi(ll a, ll b){
    return ((a%MOD)*(binpow(b,MOD-2)%MOD))%MOD;
}
ll mult(ll a, ll b){
    return ((a%MOD)*(b%MOD))%MOD;
}
ll add(ll a, ll b){
    return ((a%MOD)+(b%MOD))%MOD;
}
ll sub(ll a, ll b){
    return (((a%MOD)-(b%MOD))%MOD+MOD)%MOD;
}

template<class T, int N> struct Matrix{
    typedef Matrix M;
    array<array<T,N>,N> d{};
    M operator *(const M& m) const{
        M a;
        rep(i,0,N) rep(j,0,N)
            rep(k,0,N){
            //a.d[i][j]+=d[i][k]*m.d[k][j];
            a.d[i][j] = add(a.d[i][j],mult(d[i][k],m.d[k][j]));
            }
        return a;
    }
    M operator^ (ll p) const{
       assert(p>=0);
       M a,b(*this);
       rep(i,0,N) a.d[i][i] = 1;
       while(p){
        if(p&1) a = a*b;
        b = b*b;
        p>>=1;
       }
       return a;
    }
};

int main()
{
    ll a, b,n;
    cin>>a>>b>>n;
    n++;
    Matrix<ll,2> rotation;
    ll v1 = divi(sub(mult(a,a),mult(b,b)),add(mult(a,a),mult(b,b)));
    ll v2 = divi(mult(2*a,b),add(mult(a,a),mult(b,b)));
    rotation.d = {{{v1,v2},{sub(0,v2),v1}}};
    rotation = rotation^n;
    //cout<<sub(0,rotation.d[0][0])<<endl;
    //cout<<sub(0,rotation.d[0][1])<<endl;
    //cout<<sub(0,rotation.d[1][0])<<endl;
    cout<<sub(0,rotation.d[1][1])<<endl;
    
    return 0;
}
