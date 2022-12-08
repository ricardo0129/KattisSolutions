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
    int x, y,z;
    cin>>x>>y>>z;
    int d1 = y-x;
    int d2 = z-y;
    if(d1>0 != d2>0) cout<<"turned\n";
    else if(abs(d1)<abs(d2)) cout<<"accelerated\n";
    else if(abs(d1)>abs(d2)) cout<<"braked\n";
    else cout<<"cruised\n";
    return 0;
}
