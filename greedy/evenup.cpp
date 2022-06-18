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

int A[(int)1e5];
int n;

int main()
{
	cin>>n;
	FOR(i,n) cin>>A[i];
	stack<int> q;
	int i=0;
	while(i<n){
		if(i!=n-1 && A[i]%2==A[i+1]%2){
			i+=2;
		}
		else{
			if(!q.empty() && q.top()%2==A[i]%2){
				q.pop();
				i++;
			}	
			else{
				q.push(A[i]);
				i++;
			}
		}
	}
	cout<<q.size()<<endl;

	return 0;
}
