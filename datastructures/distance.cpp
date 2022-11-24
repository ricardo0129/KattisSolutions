#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

ll solve(vll A){
    int n = A.size();
    ll pre[n];
    ll curr = 0;
    FOR(i,n){
        curr+=A[i];
        pre[i] = curr;
    }
    ll tot = 0;
    for(int i = 1;i<n;i++){
        tot+= (i+1) * A[i] - pre[i];
    }
    return tot;
}

int main()
{
    int n;
    cin>>n;
    vll X(n), Y(n);
    FOR(i,n){
        cin>>X[i]>>Y[i];
    }
    ll ans = 0;
    sort(X.begin(),X.end());
    sort(Y.begin(),Y.end());
    ans+=solve(X);
    ans+=solve(Y);
    cout<<ans<<endl;
    return 0;
}
