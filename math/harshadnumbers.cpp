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

bool check(ll v){
    ll sum = 0;
    ll x = v;
    while(v){
        sum+=v%10;
        v/=10;
    }
    return x%sum==0;
}
int main()
{
    ll n;
    cin>>n;
    while(true){
       if(check(n)) break; 
       n++;
    }
    cout<<n<<endl;
    return 0;
}
