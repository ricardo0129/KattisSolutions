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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans = 0;
        multiset<ll> pq;
        FOR(i,n){
            int x;
            cin>>x; pq.insert(x);
        }
        while(pq.size()>=2){
            ll ff = *pq.begin(); pq.erase(pq.begin());
            ll ss = *pq.begin(); pq.erase(pq.begin());
            ans+=ff+ss;
            pq.insert(ff+ss);
        }
        //if(n==1) ans+=*pq.begin();
        cout<<ans<<endl;
    }
    return 0;
}
