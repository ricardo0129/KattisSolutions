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
    int n,k;
    cin>>n>>k;
    vector<bool> safe(n);
    FOR(i,k){
        int h;
        cin>>h;
        safe[h-1] = true;
    }
    vi closest(n);
    int curr = n;
    for(int i=n-1;i>=0;i--){
        if(safe[i]) curr = i;
        closest[i] = curr;
    }
    ll ans = 0;
    FOR(i,n){
        ans+=n-closest[i];
    }
    cout<<ans<<endl;
    return 0;
}
