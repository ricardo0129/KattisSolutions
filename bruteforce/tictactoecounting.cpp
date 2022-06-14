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

map<string,int> x,o;
bool winner(string s){
	bool win = false;
	FOR(i,3){
		win |= (s[0+i*3]==s[1+i*3] && s[1+i*3]==s[2+i*3]) && s[0+i*3]!='E';
		win |= (s[0+i]==s[3+i] && s[3+i]==s[6+i]) && s[i]!='E';
	}
	win |= (s[0]==s[4] && s[4]==s[8]) && s[0]!='E';
	win |= (s[2]==s[4] && s[4]==s[6]) && s[2]!='E';
	return win;
}
void solve(string s,int t){
	if(winner(s)){
		if(t%2==0) o[s]=1;
		else x[s]=1;
		return;
	}
	FOR(i,9){
		if(s[i]=='E'){
			string x1 = s;
			x1[i] = '0'+(t%2);
			solve(x1,t+1);
			if(t%2==0) x[s]+=x[x1];
			else o[s]+=o[x1];
		}
	}
}

int main()
{
	solve("EEEEEEEEE",0);
	int t;
	cin>>t;
	while(t--){
		string in;
		cin>>in;
		FOR(i,9){
			if(in[i]=='.') in[i] = 'E';
			else if(in[i]=='X') in[i] = '0';
			else if(in[i]=='O') in[i] = '1';
		}
		cout<<in<<endl;
		cout<<x[in]<<" "<<o[in]<<endl;
	}
	
	return 0;
}
