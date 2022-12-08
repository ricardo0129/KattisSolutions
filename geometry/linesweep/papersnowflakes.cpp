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

struct event{
    ll x;
    int type;
    event(){
    }
    event(ll a,int t){
        x = a;
        type = t;
        //0 is add 
        //1 is sub
        //2 is calculate
    }
    bool operator< (const event& lhs) const {
        if(x==lhs.x) return type==2;
        return x<lhs.x;
    }
};
int main()
{
    int n,m;
    cin>>n>>m;
    ll l; cin>>l;
    vector<pll> intervals;
    pll curr = {0,l};
    vll fold(n);
    vll cuts(m);
    FOR(i,n){
        cin>>fold[i];
    }
    FOR(i,m){
        cin>>cuts[i];
    }
    FOR(i,n){
        ll new_size = fold[i];
        if(i%2==0){
            //folding from right to left 
            pll fixed = {curr.f,curr.s-fold[i]};
            intervals.pb(fixed);
            curr = {curr.s-fold[i]-new_size,curr.s-fold[i]};
        }
        else{
            //folding from left to right
            pll fixed = {curr.f+fold[i],curr.s};
            intervals.pb(fixed);
            curr = {curr.f+fold[i],curr.f+fold[i]+new_size};
        }
    }
    intervals.pb(curr);
    vector<event> E;
    for(auto x: intervals){
        E.pb(event(x.f,0));
        E.pb(event(x.s,1));
    }
    FOR(i,m){
        E.pb(event(cuts[i],2));
    }
    sort(E.begin(),E.end());
    ll sum=0;
    ll endsum=0;
    ll cc = 0;
    for(auto e: E){
       if(e.type==0){
           endsum+=e.x;
           cc++;
       }
       if(e.type==1){
           sum += cc*(e.x)-endsum;
           cc--;
           endsum = cc*e.x;
       }
       if(e.type==2){
           sum+= cc*e.x-endsum;
           endsum = cc*e.x;
           cout<<sum<<endl;
           sum = 0;
       }
    }
    cout<<sum<<endl;
        

    
    return 0;
}
