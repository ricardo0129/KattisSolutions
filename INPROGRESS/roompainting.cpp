#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)

int main()
{
        int n,m;
        cin>>n>>m;
        vll A(n), B(m);
        FOR(i,n) cin>>A[i];
        FOR(i,m) cin>>B[i];
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        ll wasted=0;

        FOR(i,m){
                int L = 0, R = n-1;
                int ans = R;
                while(L<=R){
                        int M  = (L+R)/2;
                        if(A[M]>=B[i]){
                                ans = M;
                                R = M-1;
                        }
                        else L = M+1;
                }
                //cout<<A[ans]<<" "<<B[i]<<endl;
                ll x = A[ans]-B[i];
                assert(x>=0);
                wasted+=A[ans]-B[i];
        }
        cout<<wasted<<endl;

	return 0;
}
