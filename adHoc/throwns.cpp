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
	int n,k;
	cin>>n>>k;
	vector<string> in(k);
	stack<int> pos;
	int pre=0;
	while(k){
		string in;
		cin>>in;
		if(in[0]=='u'){
			string times;
			cin>>times;
			int j = stoi(times);
			FOR(i,j){
				pre = pos.top();
				pos.pop();
			}
			k--;
		}
		else{
			k--;
			pos.push(pre);
			int d = stoi(in);
			if(d>=0)
			 pre = (pre+d)%n;
			else
			 pre = (((pre+d)%n)+n)%n;

		}
	}
	cout<<pre<<endl;
	return 0;
}
