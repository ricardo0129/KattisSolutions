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
        vector<double> A(4);
        double mini=INT_MAX,maxi=INT_MIN,sum=0;
        FOR(i,4){
                cin>>A[i];
                mini = min(mini,A[i]);
                maxi = max(maxi,A[i]);
                sum+=A[i];
        }
        double t;
        cin>>t;
        double x1 = (sum-mini)/3.0;
        double x2 = (sum-maxi)/3.0;

        if( x1-t<=1e-3){
                cout<<"infinite\n";
        }
        else if( x2-t>1e-3){
                cout<<"impossible\n";
        }
        else{
                printf("%.2lf\n",3*t-sum+mini+maxi);
        }

	return 0;
}
