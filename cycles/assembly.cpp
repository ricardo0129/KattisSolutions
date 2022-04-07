/*
 * First observation is that since blocks can reflected and rotated the geometry of the problem is irrelavent. 
 * We only have to find some blocks that create an infinte chain. If we model this as a graph problem 
 * this is just finding if there exist one cycle. However, the hardpart is determining how to model this as a graph 
 *
 * If we attempt to build a graph on the individual problems we run into a problem. Since there can be up to 40'000 blocks. 
 * We can end up building a graph which O(N^2) edges which is too slow. 
 *
 * Our second observation is we can just build a graph on the possible side values eg. A+, C-,D+,E-,...
 * Image if we have a block with sides {C+,B-,D+,00} then we can redude the sides to {C+,B-,D+} since 00 doesnt matter. 
 * Also the ordering of these values is irrelavant. But we do know if we also have a block with values {C-,F+,K+,Z-}
 * We can actually go from the first block to the second block using the C sides as basically bridges. 
 * More discretely. For the first block we can use side B- to go to a side B+. This means if we are building a directed graph 
 * block one will give us edges {C+,B-,D+}  C+->B+  C+->D-  B-->C+  B-->D-  D+->B+ D+->C-.We build a graph on all 26*2 nodes.
 * and just check cycles this gives us the answer whether the molecule is bounded or unbounded. 
 */
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

const int N = (int)40000;

bool cycle = false;
int color[26*2];
set<int> G[26*2];

int opposite(int x){
	if(x<26) return x+26;
	return x-26;
}
void dfs(int u){
	color[u] = 1;
	for(int v:G[u]){
			if(color[v]==0){
				dfs(v);
			}
			else if(color[v]==1){
				cycle = true;
			}
	}
	color[u] = 2;
}
int main()
{
	int n;
	cin>>n;	
	for(int i=0;i<n;i++){
			string in;
			cin>>in;
			vector<int> x;
			for(int j=0;j<4;j++){
					if(in[j*2]!='0'){
						int c = in[j*2]-'A';
						int pos = in[j*2+1]=='+';
						x.push_back(c+(pos?0:26));
					}
			}
			for(int j=0;j<x.size();j++){
				for(int k=0;k<x.size();k++){
					if(k==j) continue;
					G[x[j]].insert(opposite(x[k]));	
				}
			}
	}
		
	for(int i=0;i<26*2;i++){
		if(color[i]==0)
		dfs(i);
	}

	if(cycle) cout<<"unbounded\n";
	else cout<<"bounded\n";


    return 0;
}
