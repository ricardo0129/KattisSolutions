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

int main()
{
    int n,m,k; cin>>n>>m>>k;
    vll A(n);
    FOR(i,n) cin>>A[i];
    vll taken(n, 0);
    stack<int> avail;
    ll curr = 0;
    for(int i=0;i<n;i++) {
        if(i-m>=0) {
            curr -= taken[i-m];
        }
        if(i<n && A[i])
            avail.push(i); 
        while(curr<m && avail.size()) {
            int index = avail.top();
            avail.pop();
            if(index<=i-m) continue;
            ll x = A[index]; 
            ll r = min(x, m-curr);
            A[index]-=r;
            curr+=r;
            taken[index]+=r;
            if(A[index]) avail.push(index); 
        }
    }
    ll ans = 0;
    for(ll x: taken){
        ans+=x;
        cout<<x<<" ";
    }
    cout<<endl;
    cout<<ans<<endl;

    return 0;
}
