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
map<string,int> mp;
vi G[N];
vector<string> names;
bool vist[N];
void solve(int u){
    vist[u] = true;
    for(int v:G[u]){
        if(!vist[v]) solve(v); 
    }
}
int indeg[N];
int main()
{
    int n;
    cin>>n;
    cin>>ws;
    FOR(i,n){
        string line;
        getline(cin,line);
        stringstream ss(line);
        string x;
        ss>>x;
        x.pop_back();
        if(mp.count(x)<=0){
            mp[x] = mp.size();
            names.pb(x);
        }
        int u = mp[x];
        string y;
        while(ss>>y){
            if(mp.count(y)<=0){
                mp[y] = mp.size();
                names.pb(y);
            }
            int v = mp[y];
            G[v].pb(u);
        }
    }
    string x;
    cin>>x;
    solve(mp[x]);
    FOR(i,n){
        if(!vist[i]) G[i].clear();
    }
    FOR(i,n){
        for(int v:G[i]){
            indeg[v]++;
        }
    }
    queue<int> q;
    q.push(mp[x]);

    while(!q.empty()){
        int u = q.front(); q.pop();
        cout<<names[u]<<endl;
        for(int v:G[u]){
           indeg[v]--; 
           if(indeg[v]==0){
                q.push(v);
           }
        }
    }
    return 0;
}
