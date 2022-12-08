#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define pii pair<int,int>
#define pdi pair<double,int>
#define pll pair<ll,ll>
#define vll vector<ll>
#define FOR(i,n) for(int i=0;i<n;i++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second

const int MOD = (int)1e9+7;

const int N  = 10080;
vector<pair<int,double>> G[N];
int main()
{
    int n,m,r;
    scanf("%d %d %d", &n, &m, &r);
    vector<vector<pii>> cars(n);
    pii acm;
    scanf("%d %d %d", &acm.s,&acm.s,&acm.f);
    acm.s+=acm.f;
    int carlen = acm.s-acm.f;
    FOR(i,m-1){
        int lane,len,pos;
        scanf("%d %d %d", &lane, &len, &pos);
        cars[lane].pb({pos,pos+len});
    }
    vector<vector<pii>> spaces(n);
    map<pii,int> mp;
    FOR(i,n){
        sort(cars[i].begin(),cars[i].end());
        int l = 0;
        FOR(j,sz(cars[i])){
           mp[make_pair(i,(int)spaces[i].size())] = mp.size();
           spaces[i].pb({l,cars[i][j].f}); 
           l = cars[i][j].s;
        }
        mp[make_pair(i,(int)spaces[i].size())] = mp.size();
        spaces[i].pb({l,r});
    }
    FOR(i,n-1){
        FOR(j,sz(spaces[i])){
            FOR(k,sz(spaces[i+1])){
                pii A = spaces[i][j];
                pii B = spaces[i+1][k];
                pii merged = {max(A.f,B.f),min(A.s,B.s)};
                if(merged.s-merged.f>=carlen){
                    int u = mp[make_pair(i,j)];
                    int v = mp[make_pair(i+1,k)];
                    double p_len = merged.s-merged.f;
                    double vv = (p_len-carlen)/2.0;
                    G[u].pb({v,vv});
                    G[v].pb({u,vv});
                }
            }
        }
    }
    set<int> finals;
    FOR(j,sz(spaces[n-1])){
        finals.insert(mp[make_pair(n-1,j)]);
    }
        

    int start = -1;
    double d = 1e17;
    for(int i=0;i<sz(spaces[0]);i++){
        pii x = spaces[0][i];
        if(x.f<=acm.f && acm.s<=x.s){
           start = mp[make_pair(0,i)];
           d = min(d,(double)(acm.f-x.f));
           d = min(d,(double)(x.s-acm.s));
        }
    }
    assert(start!=-1);
    priority_queue<pdi> pq;
    vector<double> dist(sz(mp),-1e17);
    dist[start] = d;
    pq.push({dist[start],start});
    while(!pq.empty()){
        pdi ff = pq.top(); pq.pop();
        //if(dist[ff.s]>ff.f) continue;
        int u = ff.s;
        assert(dist[u]>=0);
        if(finals.find(u)!=finals.end()){
            printf("%.8lf\n",dist[u]);
            return 0;
        }
        for(pair<int,double> v:G[u]){
            if(dist[v.f]<min(dist[u],v.s)){
                dist[v.f] = min(dist[u],v.s);
                pq.push({dist[v.f],v.f});
            }
        }
    }
    cout<<"Impossible\n";

    return 0;
}
