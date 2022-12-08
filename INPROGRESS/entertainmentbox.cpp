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
    int n,k;
    cin>>n>>k;
    vector<pii> A(n);
    for(pii& a: A) cin>>a.f>>a.s;
    sort(A.begin(),A.end(),[](pii& a, pii& b){
        return a.s<b.s;
    });
    multiset<int> mp;
    int ans =0 ;
    for(pii a: A){
        auto it = mp.upper_bound(a.f);
        if(it!=mp.begin()){
            it--;
            mp.erase(it);
            mp.insert(a.s);
            ans++;
        }else if(mp.size()<k){
            mp.insert(a.s);
            ans++;
        }
    }
    cout<<ans<<endl;

    
    return 0;
}
