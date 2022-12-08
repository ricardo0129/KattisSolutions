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
const int N = 3e5+1;
vi G[N];
int indeg[N];
int parent[N];
void dfs(int u,int p){
    parent[u] = p;
    for(int v:G[u]){
        dfs(v,p);
    }
}
int main()
{
    int n;
    cin>>n;
    map<string,int> mp;
    vector<string> names;
    memset(indeg,0,sizeof indeg);
    vi small;
    FOR(i,n){
        string a,b;
        cin>>a>>b;
        if(mp.count(a)<=0){
            mp[a] = mp.size();
            names.pb(a);
        }
        if(mp.count(b)<=0){
            mp[b] = mp.size();
            names.pb(b);
        }
        small.pb(mp[a]);
        indeg[mp[a]]++;
        G[mp[b]].pb(mp[a]);
    }
    assert((int)names.size()<N);
    FOR(i,names.size()){
        if(indeg[i]==0){
            dfs(i,i);
        }
    }
    FOR(i,small.size()){
        cout<<names[small[i]]<<" "<<names[parent[small[i]]]<<endl;
    }

    return 0;
}
