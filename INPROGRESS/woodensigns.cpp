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

int n;
int solve(int i, bool left){
    if(i>n) return 1;

}
int main()
{
    cin>>n;
    vi A(n);
    FOR(i,n) vin>>A[i];
    int ans = 0;
    if(A[0]<A[1]) ans = solve(1,1);
    else ans = solve(1,0);
    cout<<ans<<endl;
    return 0;
}
