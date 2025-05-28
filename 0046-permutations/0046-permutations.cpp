class Solution {
public:
    //All elt are distinct
    //Decision: Permutations starting with elt and mark them visited keeping visited array
    //Subproblem: Visited array stores if an idx is visited
    //Base case: i==n

    void f(vector<int> &nums, vector<int> &visited,vector<int> & currSet, vector<vector<int>> & res){
        int n=nums.size();
        int i=currSet.size();
        //Base
        if(i==n){
            res.push_back(currSet);
        }

        //Recurrance: Permutatations starting with a elt
        for(int j=0; j<n; j++){
            if(visited[j]) continue;
            currSet.push_back(nums[j]);
            visited[j]=1;
            f(nums,visited, currSet, res);
            visited[j]=0;
            currSet.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> visited(n,0);
        vector<int> currSet;
        vector<vector<int>>res;

        f(nums, visited, currSet, res);
        return res;
    }
};