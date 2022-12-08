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
    vi A(n);
    FOR(i,n) cin>>A[i];
    sort(A.begin(),A.end());
    int ans = 0;
    int j = 1;
    for(int i=n-1;i>=0;i--){
        ans = max(ans,A[i]+(++j));
    }
    cout<<ans<<endl;
    return 0;
}
