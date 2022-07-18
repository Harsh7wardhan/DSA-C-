class Solution {
public:
    
    void sum(vector<int>& candidates,int i,int target,vector<int> &r,vector<vector<int>> &ans)
    {
        if(target==0)
        {
            ans.push_back(r);   
            return ;
        }
        
        while(i<candidates.size() && target-candidates[i] >=0)
        {
            r.push_back(candidates[i]);
            
            //recur
            sum(candidates,i,target-candidates[i],r,ans);
            i++;
            
            //backtrack
            r.pop_back();
        }
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         sort(candidates.begin(),candidates.end()); // sort candidates array
        
        // remove duplicates
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        vector<int> r;
        vector<vector<int>> ans;
        
        sum(candidates,0,target,r,ans);
        
        return ans;
        
    }
};