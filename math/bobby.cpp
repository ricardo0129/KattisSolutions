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
int nck(int n, int k){
    if(k==n) return 1;
    if(k==0) return 1;
    if(k>n) return 0;
    return nck(n-1,k-1)+nck(n-1,k);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int r,s,x,y,w;
        cin>>r>>s>>x>>y>>w;
        double prob_succes = 0;
        int good_sides = s-r+1;
        double p = good_sides/(double)s;
        for(int i=x;i<=y;i++){
            prob_succes+=nck(y,i)*pow(p,i)*pow(1-p,y-i);
        }
        //cout<<prob_succes<<endl;
        double prob_failure = 1-prob_succes;
        double ex = 1/prob_succes;
        if(ex<w) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}
