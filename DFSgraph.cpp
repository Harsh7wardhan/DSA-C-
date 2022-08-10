#include<bits/stdc++.h>
using namespace std;
void dfs(int node,unordered_map<int,list<int>> &adj,vector<bool> &visited,vector<int> &smallans){
   visited[node]=true;
   smallans.push_back(node);
   for(int nbr:adj[node]){
       if(!visited[nbr]){
           dfs(nbr,adj,visited,smallans);
       }
   }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
   // Write your code here
   unordered_map<int,list<int>> adj;
   for(int i=0;i<E;i++){
       int u=edges[i][0];
       int v=edges[i][1];
       adj[u].push_back(v);
       adj[v].push_back(u);
   }
   vector<vector<int>> ans;
   vector<bool> visited(V,false);
   for(int i=0;i<V;i++){
       vector<int> smallans;
       if(!visited[i]){
           dfs(i,adj,visited,smallans);
       }
       ans.push_back(smallans);
   }
   return ans;
}