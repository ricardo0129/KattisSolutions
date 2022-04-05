/*
	The task is just asking us to see if we can reverse a given array 
	if there is a set of swap positions. 
	Lets say our array is {A1,A2,A3,A4...,An}
	then what we need to have as a final array is {An,An-1,...,A2,A1}
	We can see that A1 and An are swapped. A2 and An-2 
	Lets say we can swap position 1 with 2 then we create an undirected edge from 1->2
	This will give us a graph with N nodes and K edges. 
	Our assumption is, if there exists a path from A1->An, A2->An-2, ... 
	then we can reverse the array. 
	So this now becomes a rechability question. Can we reach A1->An. We solve this query 
	in O(1) with disjoint set union which takes O(n) to build. 
	We make O(n/2) queries. 
	total time complexity is O(n)+O(n/2) = O(n)
   */
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int> 
#define ll long long 
#define vll vector<ll> 
#define pii pair<int,int>

const int N = (int)1e6;
int parent[N];
int s[N];

void make_set(int u){
    parent[u] = u;
    s[u] = 1;
}
int find_set(int u){
    if(parent[u]==u) return u;
    return parent[u] = find_set(parent[u]);
}
void merge_set(int u, int v){
    u = find_set(u); v = find_set(v);
    if(u==v) return;
    if(s[u]<s[v]) swap(u,v);
    parent[v] = u;
    s[u]+=s[v];
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++) make_set(i);
    for(int i=0;i<k;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        merge_set(u,v);
    }
    bool ans = true;
    for(int i=0;i<n/2;i++){
        int u = find_set(i), v = find_set(n-1-i);
        if(u!=v) ans = false;
    }
    if(ans) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}
