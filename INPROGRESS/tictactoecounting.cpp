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

map<string,int> a1;
map<string,int> a2;
int won(string a, char x){
	FOR(i,3){
		if(a[i]==x && a[i+3]==x && a[i+6]==x) return true;
		if(a[3*i]==x && a[3*i+1]==x && a[3*i+2]==x) return true;
	}	
	if(a[0]==x && a[4]==x && a[8]==x) return true;
	if(a[2]==x && a[4]==x && a[6]==x) return true;
	return false;
}

pii precompute(string s, int t){
	if(won(s,'X')){
		a1[s] = 1;
		a2[s] = 0;
		return {1,0};
	}
	if(won(s,'O')){
		a1[s] = 0;
		a2[s] = 1;
		return {0,1};
	}
	pii ans = {0,0};
	if(t%2==0){
		//x plays
		FOR(i,9){
			if(s[i]=='.'){
				string ss = s;
				ss[i] = 'X';
				pii x = precompute(ss,t+1);
				ans.f+=x.f;
				ans.s+=x.s;
			}
		}
	}
	else{
		//o plays
		FOR(i,9){
			if(s[i]=='.'){
				string ss = s;
				ss[i] = 'O';
				pii x = precompute(ss,t+1);
				ans.f+=x.f;
				ans.s+=x.s;
			}
		}

	}
	a1[s] = ans.f;
	a2[s] = ans.s;
	return ans;
}

int main()
{
	precompute(".........",0);
	int t;
	cin>>t;
	while(t--){
		string state;
		cin>>state;
		if(a1.count(state)<=0) cout<<-1<<" "<<-1<<endl;
		else{
			cout<<a1[state]<<" "<<a2[state]<<endl;	
		}

	
	}


	return 0;
}
