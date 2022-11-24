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
    while(cin>>n){
        if(n==0) break;
        vector<vector<bool>> grid(500,vector<bool>(500,false));
        int ans = 0;
        FOR(i,n){
           int x1,y1,x2,y2;
           cin>>x1>>y1>>x2>>y2;
           for(int k=x1;k<x2;k++){
                for(int l=y1;l<y2;l++){
                    if(!grid[k][l]) ans++;
                    grid[k][l] = true;
                }
           }
        }
        cout<<ans<<endl;
    }
    return 0;
}
