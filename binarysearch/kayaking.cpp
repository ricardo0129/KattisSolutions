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

int B[3];
int main()
{
    int b,n,e;
    cin>>b>>n>>e;
    cin>>B[0]>>B[1]>>B[2];
    //cin>>sb>>sn>>se;
    int mk = (b+n+e)/2;
    vi speed(mk);
    FOR(i,mk)
        cin>>speed[i];
    ll l = 0, r = MOD;
    ll curr = r;
    while(l<=r){
        ll m = (r-l)/2+l;
        int A[3] = {b,n,e};
        bool valid = true;
        FOR(k,mk){
            //find the slowst kayak pair that matches s<=m
            ll best = MOD;
            pii ans = {-1,-1};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i==j && A[i]<2) continue;
                    if(i!=j && (A[i]<1 || A[j]<1)) continue;
                    ll v = speed[k]*(B[i]+B[j]);
                    if(v>=m){
                        if(ans.f==-1){
                            ans = {i,j};
                            best = v;
                        }
                        else if(v<best){
                            best = v;
                            ans = {i,j};
                        }
                    }
                }
            }
            if(ans.f==-1){
                valid = false;
            }
            A[ans.f]--;
            A[ans.s]--;
        }
        if(valid){
            curr = m;
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    cout<<curr<<endl;



   


    return 0;
}
