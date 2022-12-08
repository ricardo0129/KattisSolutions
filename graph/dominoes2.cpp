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
const int N = (int)10001;
vi G[N];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,l;
        cin>>n>>m>>l;
        FOR(i,m){
            int u, v;
            cin>>u>>v;
            G[u].pb(v);
        }
        queue<int> q;
        vector<bool> vist(n+1,false);
        FOR(i,l){
            int x; cin>>x;
            if(vist[x]) continue;
            q.push(x);
            vist[x] = true;
        }
        int ans = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            ans++;
            for(int v: G[u]){
                if(vist[v]) continue;
                vist[v] = true;
                q.push(v);
            }
        }
        cout<<ans<<endl;

        for(int i=1;i<=n;i++) G[i].clear();
    }
    return 0;
}
