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
	int i = 1, j = 10;
	bool possible = true;
	while(true){
		int x;
		cin>>x;
		if(x==0) break;
		cin>>ws;
		string res;
		getline(cin,res);
		if(res=="too high"){
			if(x<=i) possible = false;
			j = min(x-1,j);
		}
		else if(res=="too low"){
			if(x>=j) possible = false;
			i = max(i,x+1);
		}
		else{
			if(x<i || x>j) possible = false;
			if(possible) cout<<"Stan may be honest\n";
			else cout<<"Stan is dishonest\n";
			//reset 
			i = 1; j = 10;
			possible = true;
		}
	}
	return 0;
}
