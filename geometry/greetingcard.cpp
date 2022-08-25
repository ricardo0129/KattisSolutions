#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)

set<int> G[(int)1e5];
map<int,int> mp;
map<int,int> pm;
vector<int> xs;
ll d = 2018;

pll solve(ll a,ll b,ll c){
        if(4*a*c>b*b) return {-1,-1};
        ll x = sqrt(b*b-4*a*c);
        return {(-b+x)/(2*a),(-b-x)/(2*a)};
}
ll dit(ll ax, ll ay, ll bx, ll by){
        ll x = (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
        return x==d*d;
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin>>n;
        vector<pll> points;
        FOR(i,n){
                ll x,y;
                cin>>x>>y;
                points.pb(make_pair(x,y));
        }
        sort(points.begin(),points.end());
        FOR(i,n){
                if(mp.count(points[i].f)<=0){
                        mp[points[i].f] = mp.size();
                        xs.pb(points[i].f);
                }
                G[mp[points[i].f]].insert(points[i].s);
        }
        int ans = 0;
        FOR(i,n){
                pll a = points[i];
                int s = mp[a.f];
                for(int j=s;j<mp.size() && (j-s)<2022;j++){
                        pll x = solve(1,-2*a.s,(a.s*a.s)-(d*d)+(a.f-xs[j])*(a.f-xs[j]));
                        if(dit(a.f,a.s,xs[j],x.f) && G[j].find(x.f)!=G[j].end()){
                                if(  (a.f==xs[j] && a.s<x.f) || a.f!=xs[j])
                                ans++;
                        }
                        if(x.f==x.s) continue;
                        if(dit(a.f,a.s,xs[j],x.s) && G[j].find(x.s)!=G[j].end()){
                                if(  (a.f==xs[j] && a.s<x.s) || a.f!=xs[j])
                                ans++;
                        }

                }
        }
        cout<<ans<<endl;

	return 0;
}
