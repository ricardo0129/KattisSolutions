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

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,f;
        cin>>n>>f;
        vi pies(n);
        FOR(i,n) cin>>pies[i];
        double l = 0.00001, r = 1e10;
        double ans = r;
        FOR(i,100){
            double v = (l+r)/2;
            int friends = 0;
            FOR(i,n){
                double theta = (2.0*v)/(pies[i]*pies[i]);
                friends+=floor(2*M_PI/theta);
            }
            if(friends>=(f+1)){
                l = v+0.0000001;
                ans = v;
            }
            else r = v-0.0000001;
        }
        printf("%.8lf\n",ans);

    }
    return 0;
}
