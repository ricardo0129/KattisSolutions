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
	int t;
	cin>>t;
	while(t--){
                int n;
                cin>>n;
                vi A(n);
                FOR(i,n) cin>>A[i];
                int ans = -1;
                for(int i=1;i<n-1;i++){
                        vi B;
                        FOR(j,n) if(j!=i) B.pb(A[j]);
                        bool sorted = true;
                        FOR(j,B.size()-1){
                                if(B[j]>=B[j+1]) sorted = false;
                        }
                        if(sorted) ans = i;
                }
                cout<<ans+1<<endl;
	}
	return 0;
}
