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

int main()
{
    int n;
    cin>>n;
    if(n<=99){
        cout<<99<<endl;
        return 0;
    }
    //v = 99+100x
    int l = 0;
    for(int i=n;;i++)
        if(i%100==99){
            l = i;
            break;
        }
    int r = 0;
    for(int i=n;i>0;i--){
        if(i%100==99){
            r = i;
            break;
        }
    }
    if(abs(l-n)<=abs(r-n)) cout<<l<<endl;
    else cout<<r<<endl;
        
    
        

    return 0;
}
