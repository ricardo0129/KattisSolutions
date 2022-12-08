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
map<string,int> mp;
vector<string> all;
const int N = 10000;
set<int> G[N];
int color[N];
bool found;
void dfs(int u){
   color[u] = 1;
   for(int v:G[u]){
        if(color[v]==0) dfs(v);
        else if(color[v]==1){
            found = true;
        }
   }
   color[u] = 2;
}
int main()
{
    int n;
    cin>>n;
    FOR(i,n){
        string a,b;
        cin>>a>>b;
        if(mp.count(a)<=0){
            mp[a] = mp.size();
            all.pb(a);
        }
        if(mp.count(b)<=0){
            mp[b] = mp.size();
            all.pb(b);
        }
        int u = mp[a]; int v = mp[b];
        G[u].insert(v);
    }
    string in;
    while(cin>>in){
        FOR(i,mp.size()) color[i] = 0;
        found = false;
        int u = mp[in];
        dfs(u);
        if(found) cout<<in<<" safe\n";
        else cout<<in<<" trapped\n";
    }

    return 0;
}
