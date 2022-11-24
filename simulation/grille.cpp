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
    vector<string> g(n);
    FOR(i,n) cin>>g[i];
    vector<pii> unblocked;
    FOR(i,n) FOR(j,n)
       if(g[i][j]=='.') unblocked.pb({i,j}); 
    string enc;
    cin>>enc;
    string dec(n*n,'1');
    vector<vi> A(n,vi(n,0));
    FOR(i,n) FOR(j,n) A[i][j] = i*n+j;
    vector<vector<bool>> seen(n,vector<bool>(n,false));
    bool valid = true;
    int k = 0;
    FOR(i,4){
        for(auto x: unblocked){
            if(dec[A[x.f][x.s]]!='1' && dec[A[x.f][x.s]]!=enc[k]) valid = false;
            dec[A[x.f][x.s]] = enc[k++];
            seen[x.f][x.s] = true;
        }
        for(pii& x: unblocked)
            x = {x.s,n-1-x.f};
        sort(unblocked.begin(),unblocked.end());
    }
    FOR(i,n) FOR(j,n) if(!seen[i][j]){
        valid = false;
    }
    if(!valid) cout<<"invalid grille\n";
    else cout<<dec<<endl;

    
    return 0;
}
