 vector<vector<int>> printGraph(int V, vector<int> adj[]) {
       vector<int> temp;
       vector<vector<int>> ans;
   for(int i=0;i<V;i++){
       temp.push_back(i);
       for(auto j:adj[i]){
           temp.push_back(j);
       }
       ans.push_back(temp);
       temp.clear();
   }
   return ans;
   }