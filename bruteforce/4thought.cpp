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

int state[4];
map<int,string> ans;
map<int,char> sym;
void precompute(int i){
	if(i==3){
		vector<int> a;
		for(int j=0;j<4;j++) a.pb(4);
		vector<int> opp;
		for(int j=0;j<3;j++) opp.pb(state[j]);
		//div/mult
		for(int j=0;j<3;j++){
			int y = *opp.begin();
			opp.erase(opp.begin());
			if(y==0 || y==1){
				int x = *a.begin(); a.erase(a.begin());
				int z = *a.begin(); a.erase(a.begin());
				int ss;
				if(y==0){
					ss = x*z;
				}
				else{
					ss = x/z;
				}
				a.insert(a.begin(),ss);
			}
			else{
				int x = *a.begin(); a.erase(a.begin());
				a.pb(x);
				opp.pb(y);
			}
		}
		if(opp.size()<3){
			int y = *a.begin();
			a.erase(a.begin());
			a.pb(y);
		}
		int zz = opp.size();
		for(int j=0;j<zz;j++){
			int y = *opp.begin();
			opp.erase(opp.begin());
			if(y==2){
				int x = *a.begin(); a.erase(a.begin());
				int z = *a.begin(); a.erase(a.begin());
				x +=z;
				a.insert(a.begin(),x);
			}
			else{
				int x = *a.begin(); a.erase(a.begin());
				int z = *a.begin(); a.erase(a.begin());
				x -=z;
				a.insert(a.begin(),x);
			}
		}
		string in = "4 + 4 + 4 / 4 = ";
		in[2] = sym[state[0]];
		in[6] = sym[state[1]];
		in[10] = sym[state[2]];
		int val = *a.begin();
		in+=to_string(val);
		ans[val] = in;
		//cout<<in<<endl;
		return;
			
		//add/sub
	}
	for(int j=0;j<4;j++){
		state[i] = j;
		precompute(i+1);
	}
}
int main()
{
	sym[0] = '*'; sym[1] = '/'; sym[2]='+'; sym[3] = '-';
	precompute(0);

	int t;
	cin>>t;
	while(t--){
		int x;
		cin>>x;
		if(ans.count(x)>0){
			cout<<ans[x]<<endl;
		}
		else cout<<"no solution"<<endl;

	}
	return 0;
}
