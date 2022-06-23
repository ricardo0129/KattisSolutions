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
        int n;
        vi A(n);
        FOR(i,n)
                cin>>A[i];
        int highest = A[0];
        int curr = 0;
        FOR(i,n){
                if(A[i]<highest){
                        curr++;
                }
                else{

                }
        }
	return 0;
}
