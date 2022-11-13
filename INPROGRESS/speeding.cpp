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

int main()
{
    int n;
    cin>>n;
    vector<pii> all(n);
    for(auto& a: all) cin>>a.f>>a.s;
    int ans = 0;
    FOR(i,n-1){
        ans = max(ans,(all[i+1].s-all[i].s)/(all[i+1].f-all[i].f));
    }
    cout<<ans<<endl;
    return 0;
}
