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
    int n;
    cin>>n;
    vi A(n);
    FOR(i,n) cin>>A[i];
    sort(A.begin(),A.end());
    bool valid = true;
    double ans = 1e17;
    FOR(i,n){
       if(A[i]>(i+1)) valid = false;
       ans = min(ans,A[i]/(double)(i+1));
    }
    if(!valid) cout<<"impossible\n";
    else printf("%.8lf\n",ans);
    return 0;
}
