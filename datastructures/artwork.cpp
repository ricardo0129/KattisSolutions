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

struct stroke{
    int x, y;
    bool horizontal;
    int l;
    stroke(int x1, int y1, int x2, int y2){
        horizontal = y1==y2;
        x = min(x1,x2);
        y = min(y1,y2);
        l = abs(x1-x2)+abs(y1-y2)+1;
    }
};
struct dsu{
    vi parent;
    vi sz;
    dsu(int n){
        parent.resize(n);
        sz.resize(n);
        FOR(i,n){
            parent[i] = i;
            sz[i] = i;
        }
    }
    int find_parent(int u){
        if(u==parent[u]) return u;
        return parent[u] = find_parent(parent[u]);
    }
    bool merge(int u, int v){
        u = find_parent(u); v = find_parent(v);
        if(u==v) return false;
        if(sz[u]<sz[v]) swap(u,v);
        sz[u]+=sz[v];
        parent[v] = u;
        return true;
    }
};
int color[1000][1000];
int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};
int n,m,q;
int f(int i, int j){
    return i*m+j;
}
bool valid(int i, int j){
    return i>=0 && i<n && j>=0 && j<m;
}

int main()
{
    cin>>m>>n>>q;
    vector<stroke> A;
    FOR(i,q){
        int x1,y1,x2,y2;
        cin>>y1>>x1>>y2>>x2;
        x1--; y1--; x2--; y2--;
        A.pb(stroke(x1,y1,x2,y2));
    }
    for(stroke e: A){
        FOR(i,e.l){
            if(e.horizontal) color[e.x+i][e.y]++;
            else color[e.x][e.y+i]++;
        }
    }
    dsu dj(n*m);
    int components = 0;
    FOR(i,n) FOR(j,m) if(color[i][j]==0) components++;
    FOR(i,n) FOR(j,m){
        if(color[i][j]!=0) continue;
        FOR(k,4){
           int i2 = i+dx[k]; int j2 = j+dy[k];
           if(valid(i2,j2) && color[i2][j2]==0){
                if(dj.merge(f(i,j),f(i2,j2))) components--; 
           }
        }
    }
    vi ans(q);
    for(int i=q-1;i>=0;i--){
        ans[i] = components;
        FOR(j,A[i].l){
            int x,y;
            if(A[i].horizontal){
                x = A[i].x+j;
                y = A[i].y;
            }
            else{
                x = A[i].x;
                y = A[i].y+j;
            }
            color[x][y]--;
            if(color[x][y]==0){
                components++;
                FOR(k,4){
                    int i2 = x+dx[k];
                    int j2 = y+dy[k];
                    if(valid(i2,j2) && color[i2][j2]==0){
                        if(dj.merge(f(x,y),f(i2,j2))) components--;
                    }
                }
            }
        }
    }


    for(int i=0;i<q;i++) cout<<ans[i]<<endl;
    return 0;
}
