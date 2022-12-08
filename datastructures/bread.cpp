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

struct FT{
    vector<ll> s;
    FT(int n) : s(n) {}
    void update(int pos, ll diff){
        for(;pos<sz(s);pos|=pos+1) s[pos]+=diff;
    }
    ll query(int pos){
        //sum from [0,pos)
        ll res = 0;
        for(;pos>0;pos &= pos-1) res+=s[pos-1];
        return res;
    }
};
int A[100000];
int B[100000];

int main()
{
    int n;
    scanf("%d", &n);
    FOR(i,n) scanf("%d",&A[i]);
    FOR(i,n) scanf("%d",&B[i]);
    FT a(n),b(n);
    ll inv1 = 0,inv2=0;
    FOR(i,n){
        inv1+=a.query(A[i]-1);
        inv2+=b.query(B[i]-1);
        a.update(A[i]-1,1);
        b.update(B[i]-1,1);
    }
    if(inv1%2==inv2%2) printf("Possible\n");
    else printf("Impossible\n");
    return 0;
}
