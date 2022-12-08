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
    int n;
    cin>>n;
    int v=0,nv=0;
    vi A(3,0);
    vi B(3,0);
    FOR(i,n){
        string in;
        cin>>in;
        if(in[0]=='N') nv++;
        else v++;
        FOR(j,3){
            if(in[1+j]=='Y' && in[0]=='Y') A[j]++;
            if(in[1+j]=='Y' && in[0]=='N') B[j]++;
        }
    }
    FOR(i,3){
       double p1 = A[i]/(double)v;
       double p2 = B[i]/(double)nv;
       if(p2<=p1)
            cout<<"Not Effective\n";
       else{
            double p = (p2-p1)/p2;
            printf("%.8lf\n",p*100);
       }
    }
    return 0;
}
