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
    int s,n;
    cin>>s>>n;
    vi A(n);
    FOR(i,n) cin>>A[i];
    int ans = 0;
    FOR(i,n){
        int dist;
        if(i==n-1) dist =  s-A[i]+A[0]-1;
        else 
            dist = A[i+1]-A[i]-1;
        ans+=(dist-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}
