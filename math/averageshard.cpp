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
        int n,m;
        cin>>n>>m;
        vll C(n);
        ll SC = 0, SE=0;
        FOR(i,n){
            cin>>C[i];
            SC+=C[i];
        }
        vll E(m);
        FOR(i,m){
            cin>>E[i];
            SE+=E[i];
        }
        int ans = 0;
        FOR(i,n){
            bool con1 = SC*(n-1)<(SC-C[i])*(n);
            bool con2 = SE*(m+1)<(SE+C[i])*(m);
            if(con1 && con2) ans++;
        }
        cout<<ans<<endl;

    }
    return 0;
}
