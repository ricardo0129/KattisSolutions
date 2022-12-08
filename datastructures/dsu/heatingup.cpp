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
vll A;
int n;
struct interval{
    int left, right;
    ll tot;
    interval(int a, int b, ll c){
        left = a;
        right = b;
        tot = c;
    }
    interval(){}
    void merge(interval& other){
        tot+=other.tot;
        pii one = {left,right};
        pii two = {other.left,other.right};
        if(one.f>two.f) swap(one,two);
        if(two.s==n-1 &&  one.f==0){
            left = two.f;
            right = one.s;
        }
        else if(one.f<=one.s && two.f<=two.s){
            left = one.f;
            right = two.s;
        }
        else{
            if(one.f==two.s+1){
                left = two.f;
                right = one.s;
            }
            else{
                left = one.f;
                right = two.s;
            }
        }
    }
};
struct dsu{
    vi parent, sz;
    vector<interval> vals;
    int n;
    dsu(int _n){
        n = _n;
        parent.resize(n);
        sz.resize(n);
        FOR(i,n){
            parent[i] = i;
            sz[i] = 1;
            vals.pb(interval(i,i,A[i]));
        }
    }
    int find(int u){
        if(parent[u]==u) return u;
        return parent[u] = find(parent[u]);
    }
    bool merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v) return false;
        if(sz[u]<sz[v]) swap(u,v);
        sz[u]+=sz[v];
        parent[v] = u;
        //vals[u].tot+=vals[v].tot;
        vals[u].merge(vals[v]);
        return true;
    }
    ll getV(int u){
        return vals[find(u)].tot;
    }
    pii getBound(int u){
        return {vals[find(u)].left,vals[find(u)].right};
    }
    int components(){
        int first = find(0);
        FOR(i,n) if(find(i)!=first) return 0;
        return 1;
    }
};
int main()
{
    cin>>n;
    A.resize(n);
    FOR(i,n) cin>>A[i];
    ll l = 0, r = 1e13;
    ll ans = r;
    int loops = 0;
    while(l<=r){
        ll m = (r-l)/2+l;
        loops++;
        dsu dj(n);
        stack<int> q;
        FOR(i,n){
            if(A[i]<=m){
                q.push(i);
            }
        }
        int iter=0;
        while(!q.empty()){
            int u = q.top(); q.pop();
            pii inter = dj.getBound(u);
            int l = ((inter.f-1)%n+n)%n;
            int r = (inter.s+1)%n;
            bool add = false;
            if(iter>=2*n) break;
            if(dj.getV(l)<=dj.getV(u)+m){
                if(dj.merge(l,u)){
                    add = true;
                }
            }
            if(dj.getV(r)<=dj.getV(u)+m){
                if(dj.merge(r,u)){
                    add = true;
                }
            }
            if(add) q.push(u);
        }
        int cc = dj.components();
        if(cc==1){
            ans = m;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    assert(loops<50);
    cout<<ans<<endl;
    return 0;
}
