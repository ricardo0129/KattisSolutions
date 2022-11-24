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
struct Tree{
    typedef int T;
    static constexpr T unit = INT_MAX;
    T f(T a, T b) {return min(a,b);}
    vector<T> s; int n;
    Tree(int n=0, T def = unit) : s(2*n,def), n(n) {}
    void update(int pos, T val){
        for(s[pos+=n] = val; pos/=2;)
            s[pos] = f(s[pos*2],s[pos*2+1]);
    }
    T query(int b, int e){
    //[b,e]
        e++;

        T ra = unit, rb = unit;
        for(b+=n,e+=n;b<e;b/=2,e/=2){
            if(b%2) ra = f(ra,s[b++]);
            if(e%2) rb = f(s[--e],rb);
        }
        return f(ra,rb);
    }

};

struct event{
    bool ball;
    int x1,x2,y;
    int idx;
    event(){

    }
    event(int _x1, int _x2, int _y, bool _ball){
        x1 = _x1;
        x2 = _x2;
        y  = _y;
        ball = _ball;
    }
    bool operator< (const event& lhs) const {
        return y>lhs.y;
    }
};

int main()
{
    int d,s;
    cin>>d>>s;
    vector<event> E;
    map<pii,int> mp;
    map<int,int> lower,upper;
    vector<pii> sorted_x;
    map<pii,int> segTidx;
    Tree Seg(d);
    FOR(i,d){
        int x,y;
        cin>>x>>y;
        E.pb(event(x,x,y,true));
        sorted_x.pb({x,y});
        mp[{x,y}] = i;
    }
    sort(sorted_x.begin(),sorted_x.end());
    set<int> ycords;
    set<int> xcords;
    for(pii p: sorted_x){
        if(lower.count(p.f)<=0) lower[p.f] = segTidx.size();
        upper[p.f] = segTidx.size();
        segTidx[p] = segTidx.size();
        xcords.insert(p.f);
        ycords.insert(p.s);
    }
    map<int,int> mpy;
    for(int y: ycords) mpy[y] = mpy.size();
    multiset<int> ypos[ycords.size()];
    FOR(i,s){
        int x1,x2,y;
        cin>>x1>>x2>>y;
        E.pb(event(x1,x2,y,false));
    }
    vi ans(d);
    sort(E.begin(),E.end());
    for(event e: E){
       if(e.ball){
            //insert point to data structure      
            int yy = mpy[e.y];
            ypos[yy].insert(e.x1);
            int idx = segTidx[{e.x1,e.y}];
            Seg.update(idx,e.y);
       }
       else{
            //query points (x,y) s.t.     e.x1 <= x <=e.x2  && y is the smallest
            int new_x1 = *(xcords.lower_bound(e.x1));
            int new_x2 = *(--(xcords.upper_bound(e.x2)));
            int lo = lower[new_x1];
            int hi = upper[new_x2];
            //printf("(%d,%d) -> (%d,%d)\n",e.x1,e.x2,new_x1,new_x2);
            //cout<<"RANGE:"<<lo<<" "<<hi<<endl;
            int lowest_y = Seg.query(lo,hi);
            int tree_pos = mpy[lowest_y];
            //we have the y coordinate -> get all points with x between range
            auto LO = ypos[tree_pos].lower_bound(e.x1);
            auto HI = ypos[tree_pos].upper_bound(e.x2);
            //cout<<"QUERY:"<<e.x1<<" "<<e.x2<<" "<<e.y<<endl;
            vector<pii> points;
            for(;LO!=HI;LO++){
                //ans the query for the point
                ans[mp[{*LO,lowest_y}]] = e.y;
                //remove points
                points.pb({*LO,lowest_y});
            }
            for(pii p: points){
                ypos[tree_pos].erase(p.f);
                int idx = segTidx[p];
                Seg.update(idx,INT_MAX);
            }
       }
    }

    for(auto x: ans) cout<<x<<endl;
    return 0;
}
