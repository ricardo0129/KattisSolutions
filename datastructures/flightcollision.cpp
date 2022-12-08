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

const ll INF = (ll)1e19;
ll acd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}

pll time(pll a, pll b){
    // a < b
    if(a.s>=0 && b.s>=0){
        if(b.s>=a.s) return {INF,1};
        else return {(b.f-a.f),(a.s-b.s)};
    }
    else if(a.s<0 && b.s<0){
        if(a.s<=b.s) return {INF,1};
        else return {(b.f-a.f),(a.s-b.s)};
    }
    else{
        if(a.s<b.s) return {INF,1};
        else return {(b.f-a.f),(a.s-b.s)};
    }
}
struct collision{
    int i,j;
    ll num,den;
    collision(int a, int b, ll c, ll d){
        i = a; j = b;
        num = c;
        den = d;
        ll g = acd(num,den);
        num/=g;
        den/=g;
    }
    bool operator< (const collision& lhs) const {
        if(num==INF) return false;
        if(lhs.num==INF) return true;
        //cout<<num*lhs.den<<" "<<lhs.num*den<<endl;;
        assert(num*lhs.den<INF && lhs.num*den<INF);
        assert(num*lhs.den>=0 && lhs.num*den>=0);
        return num*lhs.den < lhs.num*den;
    }
    bool operator> (const collision& lhs) const {
        if(num==INF) return true;
        if(lhs.num==INF) return false;
        //cout<<num*lhs.den<<" "<<lhs.num*den<<endl;;
        assert(num*lhs.den>=0 && lhs.num*den>=0);
        assert(num*lhs.den<INF && lhs.num*den<INF);
        return num*lhs.den > lhs.num*den;
    }
    bool operator== (const collision& lhs) const {
        return i==lhs.i && j==lhs.j && num==lhs.num && den==lhs.den;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<pll> A;
    FOR(i,n){
        ll x,v;
        cin>>x>>v;
        A.pb({x,v});
    }
    //priority_queue<collision> q;
    priority_queue<collision, vector<collision>, greater<collision> > q;

    FOR(i,n-1){
        pll t = time(A[i],A[i+1]);
        q.push(collision(i,i+1,t.f,t.s));
        //cout<<i<<" "<<i+1<<" "<<t.f<<" "<<t.s<<endl;
        assert(t.f>=0 && t.s>=0 && t.f<=INF);
    }
    set<int> avail;
    FOR(i,n) avail.insert(i);
    collision curr_time(-1,-1,0,1);
    while(!q.empty()){
        collision ff = q.top(); q.pop();
        int u = ff.i; int v = ff.j;
        //cout<<"DEL: "<<u<<" "<<v<<endl;
        if(ff.num>=INF){
            break;
        }
        if(avail.find(u)==avail.end() || avail.find(v)==avail.end()) continue;
        
        //if(ff<curr_time) continue;
        curr_time = ff;

        auto l = avail.find(u);
        auto r = avail.find(v);
        r++;
        if(l!=avail.begin() && r!=avail.end()){
            l--;
            pll t = time(A[*l],A[*r]);
            q.push(collision(*l,*r,t.f,t.s));
        }
        avail.erase(avail.find(u));
        avail.erase(avail.find(v));
    }
    cout<<avail.size()<<endl;
    if(avail.size()){
        for(auto x: avail) cout<<x+1<<" ";
        cout<<endl;
    }


    return 0;
}
