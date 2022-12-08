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

ll x,y;
int n;
set<ll> ans;
vector<int> primes;
void get(int i, ll curr){
    if(i==n){
        if(curr>=x && curr<=y) ans.insert(curr);
        return;
    }
    FOR(j,31){
        if(curr*(ll)pow(primes[i],j)<=y)
            get(i+1,curr*(ll)pow(primes[i],j));
        else break;
    } 
}

int main()
{
    while(true){
        cin>>n;
        if(n==0) break;
        primes.resize(n);
        FOR(i,n) cin>>primes[i];
        cin>>x>>y;
        ans.clear();
        get(0,1);
        int i =0 ;
        for(auto x: ans){
            if(i++==0) cout<<x;
            else cout<<","<<x;
        }
        if(ans.size()==0) cout<<"none";
        cout<<endl;

    }
    return 0;
}
