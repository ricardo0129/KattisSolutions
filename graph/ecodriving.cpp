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

template <class T> 
struct Point{
    typedef Point P;
    T x,y;
    explicit Point(T x=0, T y=0) : x(x), y(y){}
    bool operator< (P p) const { return tie(x,y)<tie(p.x,p.y); }
    bool operator== (P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+ (P p) const { return P(x+p.x,y+p.y); } 
    P operator- (P p) const { return P(x-p.x,y-p.y); } 
    T dist() const {return sqrt((double)dist2());}
    T dist2() const {return x*x+y*y;}
    T dot(P p) const {return x*p.x+y*p.y;}
    T cross(P p) const {return x*p.y-y*p.x;}
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
};

typedef Point<double> P;
bool roads[200][200];
struct edge{
    double ang, dist;
    int u,v;
    edge(int a, int b, double _ang, double _w){
        u = a;
        v = b;
        ang = _ang;
        dist = _w;
    }
};
struct state{
    double ang, dist;
    state(double a, double b){
        ang = a;
        dist = b;
    }
    bool operator< (const state& lhs) const{
        //if(ang==lhs.ang) return dist<lhs.dist;
        //return ang<lhs.ang;
        return dist<lhs.dist;
    }
    state operator+ (state p) const { return state(max(ang,p.ang),(dist+p.dist)); } 
};
vector<edge> G[200*200];
int main()
{
/*
Note this problem was a complete nightmare
*/
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int J,R,D;
    cin>>J>>R>>D;
    vector<P> junc;
    FOR(i,J){
        int x, y;
        cin>>x>>y;
        junc.pb(P(x,y));
    }
    FOR(i,R){
        int u,v;
        cin>>u>>v;
        u--;v--;
        roads[u][v] = true;
    }
    for(int i=0;i<J;i++){
        for(int j=0;j<J;j++){
            for(int k=0;k<J;k++){
                if(roads[i][k] && roads[k][j]){
                    double dist = (junc[j]-junc[k]).dist();
                    P A = (junc[k]-junc[i]);
                    P B = (junc[j]-junc[k]);
                    double theta = atan2(B.cross(A),B.dot(A));
                    //assert(theta<=M_PI);
                    //if(theta<0) theta+=2*M_PI;
                    double deg = theta*180/M_PI;
                    //printf("(%d,%d) -> (%d,%d) %.3lf %.3lf (%.3lf)\n",i+1,k+1,k+1,j+1,deg,dist,theta);
                   // assert(deg>=0);
                    G[i*J+k].pb(edge(i*J+k,k*J+j,abs(deg),dist));
                }
            }
        }
    }
    double l = 0.0, r = 360;
    double ans = 400;
    const int iters = 200;
    FOR(k,iters){
        double m = (l+r)/2;
        //dont allow deg to exceed m 
        set<pair<state,int> > q;
        vector<state> dist(J*J,state(MOD,MOD));
        //dist[0] = state(0,0);
        //q.insert({dist[0],0});
        for(int start = 0; start<J;start++){
            if(start==0) continue;
            if(roads[0][start]){
                dist[start] = state(0,(junc[start]-junc[0]).dist());
                q.insert({dist[start],start});
            }
        }
        bool reached = false;
        while(!q.empty()){
           pair<state,int> ff = *q.begin(); q.erase(q.begin());
           int u = ff.s;
           if(dist[u]<ff.f) continue;
            //cout<<1+(u/J)<<" "<<1+(u%J)<<" "<<dist[u].dist<<" "<<dist[u].ang<<endl;
            if((u)%J==(J-1) && ff.f.dist<=D){
                reached = true;
            }

           for(edge e: G[u]){
               state enew = dist[u]+state(e.ang,e.dist);
               if(enew<dist[e.v] && enew.ang<=m){
                   dist[e.v] = enew;
                   q.insert({dist[e.v],e.v});
               }
           }
        }
        if(reached){
            ans = m;
            r = m-0.00000001;
        }
        else l = m+0.00000001;
    }
    if(ans==400)
        printf("Impossible\n");
    else
        printf("%.10lf\n",ans);
    


    return 0;
}
