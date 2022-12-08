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

int l,p;
const int N = 2e5+100;
vector<pair<int,double>> G[N];
vector<pair<int,double>> GR[N];
int score[N];
vi initial;
double dp[N];

double stor[N];
double cummulative[N];
double val[N];

double solve(int u){
    if(u<l) return (double)score[u];    
    if(dp[u]!=-1) return dp[u];
    double ex = 0;
    for(auto v: G[u]){
        ex += solve(v.f)*(v.s);
    }
    return dp[u] = ex;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>l>>p;

    FOR(i,l){
       cin>>score[i]; 
    }
    vi indeg(p,0);
    vi indeg2(l,0);
    vi indegR(l+p,0);
    FOR(i,p){
        double p1, p2;
        cin>>p1>>p2;
        int v1, v2;
        cin>>v1>>v2;
        v1--;v2--;
        G[i+l].pb({v1,p1});
        G[i+l].pb({v2,p2});

        GR[v2].pb({i+l,p2});
        GR[v1].pb({i+l,p1});
        indegR[i+l]+=2;

        if(v1>=l) indeg[v1-l]++;
        else indeg2[v1]++;
        if(v2>=l) indeg[v2-l]++;
        else indeg2[v2]++;
    }
    queue<int> q;
    vector<bool> vist(l+p,false);
    FOR(i,l+p){
        stor[i] = 0.0;
        cummulative[i] = 0.0;
    }
    FOR(i,p)
        if(indeg[i]==0)
            initial.pb(i+l);
    FOR(i,l)
        if(indeg2[i]==0)
            initial.pb(i);
        else{
            q.push(i);
            stor[i] = 1.0;
        }
    FOR(i,l+p)
        dp[i] = -1;
    

    FOR(i,l+p){
        if(i<l) continue;
        double tot = 1.0;
        for(auto v: G[i])
            tot-=v.s; 
        val[i] = tot;
    }

    while(!q.empty()){
        int u = q.front(); q.pop();
        cummulative[u]+=val[u];
        for(auto v: GR[u]){
           cummulative[v.f]+=cummulative[u]*v.s;
           stor[v.f]+=stor[u]*v.s;
           indegR[v.f]--; 
           if(indegR[v.f]==0)
                q.push(v.f);
        }
    }

    double best = 0;
    for(int i: initial){
            //best = max(best,solve(i));
            double curr = cummulative[i];
            double new_ans = solve(i)/(1-curr);
            best = max(best,new_ans);
            //cout<<solve(i,MAX_ITERS-1)<<endl;
    }
    printf("%.8lf\n",best);
    return 0;
}
