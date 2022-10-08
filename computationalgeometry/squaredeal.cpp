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
struct square{
	int x,y;
	square(){
		x = 0, y = 0;
	}
	square(int _x, int _y){
		x = _x;
		y = _y;
	}
	void flip(){
		swap(x,y);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<square> A(3);
	int area = 0;
	FOR(i,3){
		cin>>A[i].x>>A[i].y;
		area+=A[i].x*A[i].y;
	}
	int sides = sqrt(area);
	if(sides*sides!=area){
		cout<<"NO\n";
		return 0;
	}
	bool valid = false;
	vi perm(3);
	FOR(i,3) perm[i] = i;
	// 1 2 3
	do{
		vector<square> sq;
		FOR(i,3) sq.push_back(A[perm[i]]);
		for(int i=0;i<(1<<3);i++){
			//all flippings
			vector<square> sq2 = sq;
			for(int j=0;j<3;j++){
				if(i&(1<<j)){
					sq2[j].flip();
				}
			}
			
			int xside1 = sq2[0].x+sq2[1].x+sq2[2].x;
			int yside1 = sq2[0].y;
			if(xside1==sides && yside1==sides && sq2[0].y==sq2[1].y && sq2[1].y==sq2[2].y) valid = true;
			int xside2 = sq2[0].x+sq2[1].x;
			int yside2 = sq2[0].y+sq2[2].y;
			if(xside2==sides && yside2==sides && (sq2[0].y+sq2[2].y)==sq2[1].y && sq2[0].x==sq2[2].x) valid = true;
		}	
	}while(next_permutation(perm.begin(),perm.end()));


	if(valid) cout<<"YES\n";
	else cout<<"NO\n";

	return 0;
}
