#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long 
#define vll vector<ll>
#define vi vector<int>
#define pll pair<ll,ll>
#define f first
#define s second
#define FOR(i,n) for(int i=0;i<n;i++)
#define pb push_back

const int MOD = (int)1e9+7;
const ll INF = (ll)1e17+7;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	set<string> all;
	cin>>ws;
	FOR(i,n){
		string in;
		getline(cin,in);
		FOR(i,in.size()){
			if(isalpha(in[i])) in[i] = tolower(in[i]);
			else if(in[i]==' ') in[i]='-';
		}
		all.insert(in);
	}
	cout<<all.size()<<endl;
	return 0;
}
