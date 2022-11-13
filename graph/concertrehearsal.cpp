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
const int N = (int)2e5+1;
vi G[N];
bool vist[N];
ll ss[N];
ll cycle_size;
int start;
int ending;
bool selfloop;
int dfs(int u){
    vist[u] = true;
    ss[u] = 1;
    for(int v:G[u]){
        if(!vist[v]) ss[u]+=dfs(v);
        else{
            start = v;
            ending = u;
            if(u==v) selfloop = true;
        }
    }
    return ss[u];
}
int delta;
void findstart(int u){
    vist[u] = true;
    start = min(start,u);
    for(int v: G[u]){
        if(!vist[v]){
            findstart(v);
        }
    }
}
void finddelta(int u){
    //cout<<"node:"<<u<<endl;
    vist[u] = true;
    for(int v:G[u]){
        if(!vist[v]){
            finddelta(v);
            if(v<u) delta++;
        }
    }
}

ll prefix[N];
ll n,p,k;
ll getsum(int i, int j){
    //get sum from i->j in circular array 
    if(i<=j){
        ll sum = prefix[j]; 
        if(i!=0) sum-=prefix[i-1];
        return sum;
    }
    ll sum = prefix[j];
    sum+=prefix[n-1]-prefix[i-1];
    return sum;
}
int main()
{
    cin>>n>>p>>k;
    vll A(n);
    ll tot=0;
    FOR(i,n){
        cin>>A[i]; 
        tot+=A[i];
        prefix[i] = tot;
    }
    FOR(i,n){
        ll curr =0 ;
        int last = -1;
        //speed up later currently O(n^2)
        int l = 0, r = n-1;
        while(l<=r){
            int m = (l+r)/2;
            ll sum = getsum(i,(i+m)%n);
            if(sum>p%tot){
                //look left
                r = m-1;
                last = (i+m)%n;
            }
            else{
                //look right
                l = m+1;
            }
        }
        /*
        FOR(j,n){
            curr+=A[(i+j)%n];      
            last = (i+j)%n;
            if(curr>p%tot) break;
        }
        */
        G[i].pb(last);
    }
    //need two pieces of information
    //legth of cycle & distance to cycle start
    //simulate until start of cycle
    //then answer becomes math equation 
    dfs(0);
    cycle_size = ss[start];
    ll distance_to_cycle = ss[0]-cycle_size;
    //now the math
    ll ans = 0;
    //cout<<start<<" "<<ending<<endl;
    //cout<<distance_to_cycle<<" "<<cycle_size<<endl;
    memset(vist,false,sizeof vist);
    findstart(start);
    memset(vist,false,sizeof vist);
    //cout<<start<<endl;
    finddelta(start);
    delta++;
    //cout<<delta<<endl;
    //
    int u = 0;
    int iters = 0;
    while(u!=start){
        ans+=(p/tot);
        int v = G[u][0];
        if(v<u) ans++;
        u = v;
        iters++;
        if(iters==k) break;
    }
    k-=iters;
    if(selfloop) ans+=(p/tot)*k;
    else{
        int fulllops = (k/cycle_size)*cycle_size;
        ans+=(p/tot)*fulllops+(fulllops/cycle_size)*delta;
        k = k%cycle_size;
        //ans+=(p/tot)*k+(k/cycle_size)*delta;
        while(k){
            ans+=(p/tot);
            int v = G[u][0];
            if(v<u) ans++;
            u = v;
            k--;
        }
    }
    cout<<ans<<endl;


    return 0;
}
