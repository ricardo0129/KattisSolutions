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
const int N = (int)1e6+1;
int parent[N];
int sz[N];
void make_set(int u){
    parent[u] = u;
    sz[u] = 1;
}
int find_set(int u){
    if(parent[u]==u) return u;
    return parent[u] = find_set(parent[u]);
}
void merge_set(int u, int v){
    u = find_set(u); v = find_set(v);
    if(u!=v){
        if(sz[u]<sz[v]) swap(u,v);
        sz[u]+=sz[v];
        parent[v] = u;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) make_set(i);
    FOR(i,q){
        char t; 
        int u,v;
        cin>>t;
        cin>>u>>v;
        if(t=='?'){
           u = find_set(u); v = find_set(v);
           cout<<((u==v)?"yes":"no")<<endl;
        }
        else{
            merge_set(u,v);
        }
    }

    return 0;
}
