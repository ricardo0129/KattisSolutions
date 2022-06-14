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

int ans;
bool check;
int gcd(int a, int b){
	if(b==0) return a;
	//cout<<a<<" "<<b<<endl;
	if(a%b!=0){
		ans++;
		if(a/b>1) check = ;
	}
	return gcd(b,a%b);
}

int main()
{
	while(true)
	{
		int a,b;
		cin>>a>>b;
		if(a==b && b==0) break;
		if(b>a) swap(a,b);
		ans = 0;
		check = false;
		gcd(a,b);
		if(ans%2==0 || check) cout<<"Stan wins\n";
		else cout<<"Ollie wins\n";
	}

	return 0;
}
