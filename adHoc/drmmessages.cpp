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
	string in;
	cin>>in;
	int n = in.size();
	string one = in.substr(0,n/2);
	string two = in.substr(n/2,n/2);
	int rot1 = 0, rot2 = 0;
	FOR(i,n/2){
		rot1+=one[i]-'A';
		rot2+=two[i]-'A';
	}
	FOR(i,n/2){
		one[i] = (((one[i]-'A')+rot1)%26)+'A';
		two[i] = (((two[i]-'A')+rot2)%26)+'A';
	}
	FOR(i,n/2){
		one[i] = ((one[i]-'A')+(two[i]-'A'))%26+'A';
	}
	cout<<one<<endl;
	return 0;
}
