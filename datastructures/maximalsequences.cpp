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
const int inf = 1e7;
struct Node{
    Node *l = 0 , *r = 0;
    int lo,hi,mset=inf,madd=0,val=0;
    int f(int a, int b){ return min(a,b) ;}
    Node(int lo, int hi): lo(lo),hi(hi) {}
    Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
        if(lo+1<hi){
            int mid = lo+(hi-lo)/2;
            l = new Node(v,lo,mid); r = new Node(v,mid,hi);
            val = f(l->val,r->val);
        }
        else val = v[lo];
    }
    int minq(int L, int R){
        if(R<=lo || hi<=L) return inf;
        if(L<=lo && hi<=R) return val;
        push();
        return f(l->minq(L,R),r->minq(L,R));
    }
    void set(int L, int R, int x){
        if(R<=lo || hi<=L) return;
        if(L<=lo && hi<=R) mset = val = x, madd = 0;
        else{
            push(), l->set(L,R,x), r->set(L,R,x);
            val = f(l->val,r->val);
        }
    }
    void add(int L, int R, int x){
        if(R<=lo || hi<=L) return;
        if(L<=lo && hi<=R){
            if(mset!=inf) mset+=x;
            else madd += x;
            val+=x;
        }
        else{
            push(), l->add(L,R,x), r->add(L,R,x);
            val = f(l->val,r->val);
        }
    }
    void push(){
        if(!l){
            int mid = lo+(hi-lo)/2;
            l = new Node(lo,mid); r = new Node(mid,hi);
        }
        if(mset!=inf){
            l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
        }
        else if(madd){
            l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
        }
    } 
        

};

struct query{
    vi vals;
    int idx;
    int qn;
    query(int i, int _qn){
        idx = i;
        qn = _qn;
    }
    void add(int n){
        vals.pb(n);
    }
};

int main()
{
    int n;
    cin>>n;
    vi A(n);
    vector<pii> vals;
    map<int,int> right;
    map<int,int> left;
    FOR(i,n){
        cin>>A[i];
        vals.pb({A[i],i});
        right[A[i]] = i;
    }
    map<int,int> mp;
    sort(vals.begin(),vals.end());
    for(int i=0;i<n;i++){
        mp[vals[i].s] = i;
    }
    int q;
    cin>>q;
    vector<vector<query>> Q(n);
    vi ans(q);
    FOR(i,q){
        int idx;
        cin>>idx;
        idx--;
        query q(idx,i);
        int k; cin>>k;
        FOR(j,k){
            int x;
            cin>>x;
            q.add(x);
        }
        Q[idx].pb(q);
    }
    vi v(n,inf);
    Node* tr = new Node(v,0,sz(v));
    for(int i=n-1;i>=0;i--){
        tr->set(mp[i],mp[i]+1,i);
        left[A[i]] = i;
        //process all queries at this index 
        for(query q: Q[i]){
            for(int x: q.vals){
                if(left.count(x)<=0) continue;
                tr->add(mp[left[x]],mp[right[x]]+1,inf);
            }
            int right_most = tr->minq(0,n);
            if(right_most >= n)
                ans[q.qn] = n-i;
            else
                ans[q.qn] = right_most-i;

            for(int x: q.vals){
                if(left.count(x)<=0) continue;
                tr->add(mp[left[x]],mp[right[x]]+1,-inf);
            }
        }
    }

    
    for(int x: ans) cout<<x<<endl;

    return 0;
}
