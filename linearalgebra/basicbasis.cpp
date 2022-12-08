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

const int LOG_A = 200;
bitset<LOG_A> basis[LOG_A];
int sz;
bool insert(bitset<LOG_A> mask){
	for(int i=0;i<LOG_A;i++){
		if(mask[i]==0) continue;
		if(basis[i].count()==0){
			basis[i] = mask;
			sz++;
			return true;
		}
		mask^=basis[i];
	}
	//not inserted
	return false;
}
bool inset(bitset<LOG_A> mask){
	for(int i=0;i<LOG_A;i++){
		if( mask[i]==0) continue;
		if(basis[i].count()==0){
			return false;
		}
		mask^=basis[i];
	}
	return true;
}
vector<bitset<LOG_A>> A,B;
map<char,int> mp;
bitset<LOG_A> tobit(string hx){
	reverse(hx.begin(),hx.end());
	bitset<LOG_A> x;
	FOR(i,hx.size()){
		int v = mp[hx[i]];	
		FOR(j,4){
			x.set(i*4+j,v&(1<<j));
		}
	}
	return x;
}
bool iszer(bitset<LOG_A> a){
	return !a.any();
}
int main()
{
	FOR(i,10) mp[(char)('0'+i)] = i;
	int x = 10;
	for(char i='a';i<='f';i++) mp[i] = x++;

	int n,m,k;
	cin>>n>>m>>k;
	FOR(i,n){
		string in;
		cin>>in;
		A.pb(tobit(in));
	}
	FOR(i,m){
		string in;
		cin>>in;
		B.pb(tobit(in));
	}
	int ans[m];
	FOR(i,m) ans[i] = -1;
	int zero = -1;
	FOR(i,n){
		if(!insert(A[i]) && zero==-1) zero = i+1;
		FOR(j,m){
			if(ans[j]==-1){
				if(inset(B[j])) ans[j] = i+1;
			}
		}
	}
	FOR(i,m){
		if(iszer(B[i])) ans[i] = zero;

	}
	FOR(i,m) cout<<ans[i]<<endl;
	
	return 0;
}
