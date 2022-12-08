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
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
const int MOD = (int)1e9+7;
bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
if (A[a] != L) return 0;
A[a] = -1;
for (int b : g[a]) if (B[b] == L + 1) {
B[b] = 0;
if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
return btoa[b] = a, 1;
}
return 0;
}
int hopcroftKarp(vector<vi>& g, vi& btoa) {
int res = 0;
vi A(g.size()), B(btoa.size()), cur, next;
for (;;) {
fill(all(A), 0);
fill(all(B), 0);
cur.clear();
for (int a : btoa) if(a != -1) A[a] = -1;
rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
for (int lay = 1;; lay++) {
bool islast = 0;
next.clear();
for (int a : cur) for (int b : g[a]) {
if (btoa[b] == -1) {
B[b] = lay;
islast = 1;
}
else if (btoa[b] != a && !B[b]) {
B[b] = lay;
next.push_back(btoa[b]);
}
}
if (islast) break;
if (next.empty()) return res;
for (int a : next) A[a] = lay;
cur.swap(next);
}
rep(a,0,sz(g))
res += dfs(a, 0, g, btoa, A, B);
}
}
struct flight{
    //from airport s->f leaving at time t
    int s,f,t;
    flight(int _s, int _f, int _t){
        s = _s;
        f = _f;
        t = _t;
    }
    flight(){
        s = f = t = 0;
    }
};

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vll> dist(n,vll(n,0));
    vll inspection(n);
    FOR(i,n) cin>>inspection[i];
    vector<vll> direct(n,vll(n,0));
    FOR(i,n) FOR(j,n){
        cin>>dist[i][j];
        direct[i][j] = dist[i][j];
        dist[i][j]+=inspection[j];
        if(i==j) dist[i][j] = 0;
    }
    vector<flight> f(m);
    FOR(i,m){
       cin>>f[i].s>>f[i].f>>f[i].t; 
       f[i].s--; f[i].f--;
    }

    //all pairs shortest path
    FOR(k,n){
        FOR(i,n){
            FOR(j,n){
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    FOR(i,n){
        FOR(j,n){
            //cout<<dist[i][j]<<" ";
        }
        //cout<<endl;
    }
    vector<vi> g(m);
    //can we go from flight m to other flight

    FOR(i,m){
        FOR(j,m){
            if(i==j) continue;
            ll d1 = direct[f[i].s][f[i].f]+f[i].t+inspection[f[i].f];
            ll d2 = dist[f[i].f][f[j].s];
            if(d1+d2<=f[j].t){
                g[i].pb(j);
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    vi btoa(m,-1);
    int matching = hopcroftKarp(g,btoa);
    cout<<m-matching<<endl;



    return 0;
}
