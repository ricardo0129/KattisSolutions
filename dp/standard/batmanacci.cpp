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
const int N = (int)1e5+1;
unsigned ll fib[N];
char solve(int n, unsigned ll k){
    assert(k>=0);
    if(n==0) return 'N';
    if(n==1) return 'A';
    if(k<fib[n-2])
        return solve(n-2,k);
    return solve(n-1,k-fib[n-2]);
}
int main()
{
    ll n;
    unsigned ll k;
    cin>>n>>k;
    n--;
    k--;
    fib[0] = fib[1] = 1;
    for(int i=2;i<n;i++){
        fib[i] = fib[i-1]+fib[i-2];
        fib[i] = min(fib[i],(unsigned ll)1e18);
    }
    //cout<<fib[n-1]<<endl;
    cout<<solve(n,k)<<endl;

    return 0;
}
