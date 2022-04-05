#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

const int N = (int)1e6;
int parent[N];
int s[N];

void make_set(int u){
    parent[u] = u;
    s[u] = 1;
}
int find_set(int u){
    if(parent[u]==u) return u;
    return parent[u] = find_set(parent[u]);
}
void merge_set(int u, int v){
    u = find_set(u); v = find_set(v);
    if(u==v) return;
    if(s[u]<s[v]) swap(u,v);
    parent[v] = u;
    s[u]+=s[v];
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) make_set(i);
    for(int i=0;i<k;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        merge_set(u,v);
    }
    bool ans = true;
    for(int i=0;i<n/2;i++){
        int u = find_set(i), v = find_set(n-1-i);
        if(u!=v) ans = false;
    }
    if(ans) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
