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
    int t;
    cin>>t;
    while(t--){
        ll ans = 0;
        vi A;
        while(true){
            int x;
            cin>>x;
            if(x==0) break;
            A.pb(x);
        }
        int n = A.size();
        FOR(i,n-1){
            int allowed = min(1000000,2*A[i]);
            if(allowed<A[i+1]) ans+=A[i+1]-allowed;
        }
        cout<<ans<<endl;
    }
    return 0;
}
