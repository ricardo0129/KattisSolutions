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

const int MOD = 13;

int binpow(int a, int b){
    if(b==0) return 1;
    if(b==1) return a%MOD;
    int x = binpow(a,b/2)%MOD;
    x = (x*x)%MOD;
    if(b%2==1) x = (x*a)%MOD;
    return x%MOD;
}
int add(int x, int y){
    return (x+y)%MOD;
}
int sub(int x, int y){
    return ((x-y)%MOD+MOD)%MOD;
}
int mult(int x, int y){
    return (x*y)%MOD;
}
int divi(int x, int y){
    return mult(x,binpow(y,MOD-2));
}
int solveLinear(vector<vi>& A, vi& b, vi& x) {
    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n) assert(sz(A[0]) == m);
    vi col(m); iota(all(col), 0);

    rep(i,0,n) {
        int v, bv = 0;
        rep(r,i,n) rep(c,i,m)
        if ((v = (A[r][c])) > bv)
        br = r, bc = c, bv = v;

        if (bv == 0 ) {
            rep(j,i,n) if ((b[j]) !=0 ){
                return -1;
            }
            break;
        }

        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j,0,n) swap(A[j][i], A[j][bc]);
        //bv = 1/A[i][i];
       // rep(j,i+1,n) {
        rep(j,0,n) if (j != i) {
            int fac = divi(A[j][i],A[i][i]);
            b[j] = sub(b[j],mult(fac,b[i]));
            rep(k,i+1,m) A[j][k] = sub(A[j][k],mult(fac,A[i][k]));
        }
        rank++;
    }
    /*
    x.assign(m, 0);
    for (int i = rank; i--;) {
        b[i] = divi(b[i],A[i][i]);
        x[col[i]] = b[i];
        rep(j,0,i) b[j] = sub(b[j],mult(A[j][i] , b[i]));
    }
    */
    
    x.assign(m, -1);
    rep(i,0,rank) {
        rep(j,rank,m) if ((A[i][j]) != 0 ) goto fail;
        x[col[i]] = divi(b[i] , A[i][i]);
    fail:;
    }
    return rank;
}

const int N = 201;
vector<pii> G[N];

int main()
{
    int n,a,r,t;
    cin>>n>>a>>r>>t;
    map<pii,int> mp;
    vector<pii> edges;
    vi dist(t);
    vector<vi> all;
    FOR(i,t){
        cin>>dist[i];
        int k;
        cin>>k;
        vi path(k);
        FOR(j,k){
            cin>>path[j];
            if(j!=0){
                int u = min(path[j-1],path[j]);
                int v = max(path[j-1],path[j]);
                if(mp.count(make_pair(u,v))<=0){
                    mp[make_pair(u,v)] = mp.size();
                    edges.pb(make_pair(u,v));
                }
            }
        }
        all.pb(path);
    }
    vector<vi> A(t,vi(mp.size(),0));
    FOR(i,t){
        vi path = all[i];
        FOR(j,path.size()){
            if(j!=0){
                int u = min(path[j-1],path[j]);
                int v = max(path[j-1],path[j]);
                A[i][mp[make_pair(u,v)]]++;
            }
        }
    }
    vi x(mp.size());
    FOR(i,dist.size()){
        dist[i] = dist[i]%MOD;
    }
    FOR(i,A.size()){
        FOR(j,A[0].size()){
            A[i][j] = A[i][j]%MOD;
        }
    }
    int rank = solveLinear(A,dist,x);
    assert(rank!=-1);
    for(int i=0;i<x.size();i++){
        pii pp = edges[i];
        G[pp.f].pb(make_pair(pp.s,x[i]));
        G[pp.s].pb(make_pair(pp.f,x[i]));
    }
    vi shortest(n+1,1e7);
    shortest[a] = 0;
    set<pii> q;
    q.insert({0,a});
    while(!q.empty()){
        pii ff = *q.begin(); q.erase(q.begin());
        if(shortest[ff.s]<ff.f) continue;
        int u = ff.s;
        for(pii v:G[u]){
            if(shortest[v.f]>shortest[u]+v.s){
               shortest[v.f] = shortest[u]+v.s;
               q.insert(make_pair(shortest[v.f],v.f));
            }
        }
    }
    assert(shortest[r]!=1e7);
    cout<<shortest[r]<<endl;





    return 0;
}
