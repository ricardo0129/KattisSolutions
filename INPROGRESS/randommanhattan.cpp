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

const int MOD = (int)1e9+7;

struct Line{
    int x1,y1;
    int x2,y2;
    double m,b;
    Line(){}
    Line(int a, int b, int c, int d){
        x1 = a; y1 = b;
        x2 = c; y2 = d;
        m = getM();
        b = getB();
    }
    double getM(){
        return (y2-y1)/(double)(x2-x1);
    }
    double getB(){
        return y1-getM()*(double)x1;
    }
    bool operator< (const Line& lhs) const {
        if(lhs.m==m) return b<lhs.b;
        return m<lhs.m;
    }
    bool operator== (const Line& lhs) const {
        return lhs.m==m && b==lhs.b;
    }
    void print(){
        printf("(%d,%d) (%d %d)\n",x1,y1,x2,y2);
    }
};
struct Event{
    Line L;
    bool left;
    Event(Line l, bool _left){
        L = l;
        left = _left;
    }
    bool operator< (const Event& lhs) const{
       int a = left?min(L.x1,L.x2):max(L.x1,L.x2);
       int b = lhs.left?min(lhs.L.x1,lhs.L.x2):max(lhs.L.x1,lhs.L.x2);
       return a<b;
    }
};
int main()
{
    int n;
    scanf("%d",&n);
    vector<pii> points(n);
    FOR(i,n)
        scanf("%d %d",&points[i].f,&points[i].s);
    
    vector<Event> E;
    FOR(i,n){
        Line l = Line(points[i].f,points[i].s,points[(i+1)%n].f,points[(i+1)%n].s);
        E.pb(Event(l,false));
        E.pb(Event(l,true));
    }
    sort(E.begin(),E.end());
    multiset<Line> q;
    long double prob = 0;
    for(Event e: E){
        if(e.left){
            //add it to data structure
            printf("Add");
            e.L.print();
            q.insert(e.L);
        }
        else{
            //calcualte the answer
            printf("Remove");
            e.L.print();
            q.erase(q.find(e.L));
        }
    }
    printf("%.8Lf\n", prob);


    


    return 0;
}
