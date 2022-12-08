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

struct rec{
    //lower left corner
    int x1,y1;
    //upper right
    int x2,y2;
    rec(int _x1, int _y1, int _x2, int _y2){
        x1 = _x1; y1 = _y1;
        x2 = _x2; y2 = _y2;
    }
    rec(){}
};
struct event{
    rec R;
    bool leftend;
    event(rec _R, bool l){
        R = _R;
        leftend = l;
    }
    bool operator< (const event& lhs) const {
        int a = (leftend)?R.x1:R.x2;
        int b = (lhs.leftend)?lhs.R.x1:lhs.R.x2;
        return a<b;
    }
};
bool check(multiset<int>& q, int y1, int y2){
    //we need to check if y exists with y1<=y<y2
    auto it1 = q.lower_bound(y1);
    auto it2 = q.upper_bound(y2);
    return it1!=it2;
}
int main()
{
    int n;
    cin>>n;
    vector<rec> A(n);
    vector<event> E;
    FOR(i,n){
        cin>>A[i].x1>>A[i].y1>>A[i].x2>>A[i].y2;
        E.pb(event(A[i],true));
        E.pb(event(A[i],false));
    }
    sort(E.begin(),E.end());
    multiset<int> q;
    bool intersect = false;
    for(event e : E){
        if(e.leftend){
            //check if there is intersection with left horizontal edge and any active parrallel edges
            intersect |= check(q,e.R.y1,e.R.y2); 
            //add parallel edges
            q.insert(e.R.y1);
            q.insert(e.R.y2);
        }
        else{
            //remove parallel edges
            q.erase(q.find(e.R.y1));
            q.erase(q.find(e.R.y2));
            //check if there is intersection with right horizontal edge and any active edges
            intersect |= check(q,e.R.y1,e.R.y2); 
        }
    }
    cout<<intersect<<endl;

    return 0;
}
