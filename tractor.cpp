#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>


int a, b;
int ans = 0;
void solve(int x, int y, int n){
	queue<int> q1,q2,q3;
	q1.push(0); q2.push(0); q3.push(0);
	while(!q1.empty()){
		x = q1.front(); q1.pop();
		y = q2.front(); q2.pop();
		n = q3.front(); q3.pop();
		if(x>a || y>b) continue;
		ans++;
		q1.push(x+(1<<n)); q2.push(y); q3.push(n+1);
		q1.push(x); q2.push(y+(1<<n)); q3.push(n+1);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		ans = 0;
		solve(0,0,0);

		cout<<ans<<endl;
	}
    return 0;
}
