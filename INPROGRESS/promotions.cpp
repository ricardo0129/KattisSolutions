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

bool rechable[5000][5000];
int main()
{
    int a,b,e,p;
    cin>>a>>b>>e>>p;
    vector<vi> G(e);
    FOR(i,p){
        int u,v;
        cin>>u>>v;
        G[u].pb(v);
    }
    //vector<vector<bool>> rechable(e,vector<bool>(e,false));
    FOR(i,e){
        queue<int> q;
        vector<bool> vist(e);
        vist[i] = true;
        for(q.push(i);!q.empty();q.pop()){
            int u = q.front();
            rechable[i][u] = true;
            for(int v:G[u]){
                if(!vist[v]){
                    q.push(v); 
                    vist[v] = true;
                }
            }
        }
    }
            //Mandatory A, Mandatory B, Never
    int ans[] = {0,0,0};
    FOR(i,e){
        int c1 = 0;
        int c2 = 0;
        FOR(j,e) c1+=rechable[i][j];
        FOR(j,e) c2+=rechable[j][i];
        if(c2>b) ans[2]++;
        if(e-c1<a) ans[0]++;
        if(e-c1<b) ans[1]++;
    }
    FOR(i,3) cout<<ans[i]<<endl;

    return 0;
}
