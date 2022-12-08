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
const int N = 1006;
vi G[N];
double V[N];
pair<int,double> dp[N][2];
pair<int,double> solve(int u, int taken){
    if(dp[u][taken].f!=-1) return dp[u][taken];
    pair<int,double> ans = {0,0};
    for(int v: G[u]){
        auto x = solve(v,0);
        ans.f+=x.f;
        ans.s+=x.s;
        //cout<<ans.f<<" "<<ans.s<<endl;
    }    
    pair<int,double> base = ans;
    if(!taken){
        for(int v: G[u]){
           pair<int,double> a1 = solve(v,1);
           pair<int,double> a2 = solve(v,0); 
           a1.f+=base.f; a1.s+=base.s; 
           a1.f-=a2.f; a1.s-=a2.s;
           a1.f+=1; a1.s+=min(V[u],V[v]);
           //cout<<a1.f<<" "<<a1.s<<endl;
           ans = max(ans,a1);
        }
    }
    return dp[u][taken] = ans;
}

int main()
{
    map<string,int> mp;
    int n;
    cin>>n;
    int start = -1;
    FOR(i,n){
        string a,b;
        double v;
        cin>>a>>v>>b;
        if(mp.count(a)<=0) mp[a] = mp.size();
        if(mp.count(b)<=0) mp[b] = mp.size();
        if(b!="CEO"){
            G[mp[b]].pb(mp[a]);
        }
        else start = mp[a];
        V[mp[a]] = v;
    }
    FOR(i,n+1) FOR(j,2) dp[i][j] = {-1,-1};
    pair<int,double> ans = solve(start,0);
    printf("%d %.8lf\n",ans.f,ans.s/(double)ans.f);
    
    return 0;
}
