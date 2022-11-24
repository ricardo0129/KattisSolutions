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

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    ll a, b;
    cin>>a>>b;
    if(a%2!=b%2){
        cout<<0<<endl;
        return 0;
    }
    ll g = gcd(a,b);
    a/=g;
    b/=g;
    if(a%2==0 || b%2==0) g=0;
    cout<<g<<endl;

    return 0;
}
