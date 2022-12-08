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
    int n,t;
    cin>>n>>t;
    ll total=0;
    int maxi=0;
    FOR(i,n){
        int x;
        cin>>x;
        total+=x;
        maxi = max(maxi,x);
    }
    if((n-1)*t<maxi) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}
