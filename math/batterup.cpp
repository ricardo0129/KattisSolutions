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
    int n;
    cin>>n;
    int top = 0;
    int bot = 0;
    int x; 
    FOR(i,n){
        cin>>x;
        if(x==-1) continue;
        bot++; top+=x;
    }
    printf("%.8lf\n",top/(double)bot);
    return 0;
}
