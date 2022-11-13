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
    ll h,c;
    cin>>h>>c;
    vector<pll> values;
    FOR(i,c){
        int x,y;
        cin>>x>>y;
        values.pb(make_pair(x,y));
    }
    ll l = 0, r = 1e16;
    ll ans = r;
    while(l<=r){
        ll m = (r-l)/2+l;
        ll times = 0;
        FOR(i,c){
            if(m>values[i].f){
                //cout<<values[i].f<<" "<<values[i].s<<" "<<(m-values[i].f)/values[i].s<<endl;
                times+=(m-values[i].f)/values[i].s;
            }
            if(times>=h) break;
        }
        if(times>=h){
            r = m-1;
            ans = m;
        }
        else{
            l = m+1;
        }
    }
    FOR(i,c) ans = max(ans,values[i].f);
    cout<<ans<<endl;
    return 0;
}
